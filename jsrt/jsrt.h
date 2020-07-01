//
// Created by Duzhong Chen on 2020/6/28.
//

#ifndef JSRT
#define JSRT

#include <stdint.h>
#include <stdlib.h>
#include <locale.h>

#include "jsheap.h"

#define JS_STACK_TMP_SIZE     4
#define JS_STACK_VAR_SIZE     64
#define JS_ARR_DEFAULT_CAP    4
#define JS_SMI_OFFSET         32u
#define JS_OBJ_BUCKET_CAP     4
#define JS_TY_DOUBLE          double
#define JS_TY_CHAR            unsigned int
#define JS_TY_FLAGS           uint32_t
#define JS_TY_RC              int32_t
#define JS_INVALID_PTR        ((uint64_t)-1)
#define JS_INVALID_STR_HASH   ((uint32_t)-1)
#define JS_ANONYMOUS_FUN_NAME "anonymous"

#define JS_VAL               uint64_t
#define JS_PTR               JsObjectHead*

typedef enum : unsigned int {
    JS_UNDEFINED = 0u,
    JS_NUM       = 1u,
    JS_STR       = 2u,
    JS_BOOL      = 3u,
    JS_ARR       = 4u,
    JS_OBJ       = 5u,
    JS_FUN       = 6u
} JS_TYPE;

typedef enum : int {
    JS_ERR_TYPE_MIS        = -2,
    JS_ERR_BUF_NOT_ENOUGH  = -3,
    JS_ERR_NOT_IMPLEMENTED = -4,
} JS_ERR;

struct JSRT_CTX;
struct JsObjectHead;
struct JsFunClosureEnv;

typedef void (*JSRT_RawFunction)(struct JSRT_CTX* ctx, JS_VAL args, struct JsFunClosureEnv* env);

#define IS_SMI(x) (((JS_VAL)(x) & 1u) == 0)
#define JS_VAL_TO_PTR(x) ((JS_PTR)((x) & (~1u)))
#define PTR_TO_JS_VAL(x) ((JS_VAL)(x) | 1u)
#define SMI_TO_I32(x) ((int32_t)((JS_VAL)(x) >> JS_SMI_OFFSET))
#define I32_TO_SMI(x) ((JS_VAL)(x) << JS_SMI_OFFSET)

static const int64_t JSRT_MaxSmiValue = 0x7FFFFFFF;
static const int64_t JSRT_MinSmiValue = 0xFFFFFFFF;

#define JS_OBJ_FLAGS_TYPE    0b00000000000000000000000011111111u

#define JS_STR_FLAGS_TYPE    0b00000000000000000000011100000000u
#define JS_FLAGS_STD_STR     0b00000000000000000000000000000000u
#define JS_FLAGS_CONCAT_STR  0b00000000000000000000000100000000u

#define JS_GC_FLAGS_TYPE     0b11110000000000000000000000000000u
#define JS_FLAGS_STATIC_VAL  0b00010000000000000000000000000000u

typedef struct {
    JS_TY_FLAGS flags;
    JS_TY_RC rc;
} JsObjectHead;

#define PTR_TYPE(x) (x->flags & JS_OBJ_FLAGS_TYPE)

// String

typedef struct {
    JS_TY_FLAGS flags;
    JS_TY_RC rc;
    uint32_t      str_size;
    uint32_t      simple_hash;
} JsStrCommon ;

uint16_t JsStrDepth(JsStrCommon* str);
uint16_t JsStrNodeSize(JsStrCommon* str);

typedef struct {
    JS_TY_FLAGS flags;
    JS_TY_RC rc;
    uint32_t      str_size;
    uint32_t      simple_hash;
    // str common end

    JS_TY_CHAR   str_val[0];
} JsStdStr;

/**
 * flat array of JsStdStr,
 * good at quick concat,
 * TODO: make it a rope tree
 */
typedef struct {
    JS_TY_FLAGS  flags;
    JS_TY_RC     rc;
    uint32_t      str_size;
    uint32_t      simple_hash;
    // str common end

    uint16_t      node_size;
    uint16_t      depth;
    JsStrCommon*  left;
    JsStrCommon*  right;
} JsConcatStr;

#define JS_STR_TYPE(x) (((JsObjectHead*)x)->flags & JS_STR_FLAGS_TYPE)

// Array

typedef struct {
    JS_TY_FLAGS  flags;
    JS_TY_RC     rc;
    uint32_t      size;
    uint32_t      capacity;
    JS_VAL*       data;
} JsArray;

// Static Values

#define DEF(NAME, VAL) JS_VAL S_##NAME;

typedef struct {
    JS_VAL J_undefined;
    JS_VAL J_true;
    JS_VAL J_false;

#include "static-str.h"

} JsStaticVal;

#undef DEF

JsStaticVal *NewJsStaticVal(struct JSRT_CTX* ctx);
void FreeJsStaticVal(struct JSRT_CTX* ctx, JsStaticVal* jsv);

// StandardObject

typedef struct JsStdObjectProp {
    JsStrCommon* key;
    JS_VAL value;
    struct JsStdObjectProp* next;
} JsStdObjectProp;

// 16 bytes, is a smo
typedef struct JsStdObjectPropBucket {
    JsStdObjectProp* prop;
    struct JsStdObjectPropBucket* next;
} JsStdObjectPropBucket;

typedef struct {
    JS_TY_FLAGS flags;
    JS_TY_RC rc;
    // 8 bytes
    uint32_t prop_size;
    uint32_t bucket_cap;
    // 16 bytes
    JsStdObjectProp* start_prop;
    JsStdObjectProp* end_prop;
    // 32 bytes
    JsStdObjectPropBucket* bucket;
} JsStdObject;

// Object

typedef struct {
    JS_TY_FLAGS flags;
    JS_TY_RC rc;
    union {
        int32_t       bool_val;
        JS_TY_DOUBLE num_val;
    };
} JsObject;

#define JS_TYPE(x) (((JsObject*)x)->flags & JS_OBJ_FLAGS_TYPE)

// Function

typedef struct JsFunClosureEnv {
    uint32_t val_size;
    JS_VAL   data[0];
} JsFunClosureEnv;

typedef struct JsFunction {
    JS_TY_FLAGS flags;
    JS_TY_RC rc;
    JSRT_RawFunction  raw_function;
    JsFunClosureEnv*  closure_env;
} JsFunction;

typedef struct JsVirtualStack {
    const char*            name;
    struct JsVirtualStack* prev;
    struct JsVirtualStack* next;
    uint32_t               height;
    JS_VAL                 argument;
    JS_VAL                 temp_val[JS_STACK_TMP_SIZE];
    uint32_t               var_size;
    JS_VAL                 variable[JS_STACK_VAR_SIZE];
} JsVirtualStack;

typedef struct JSRT_CTX {
    JsVirtualStack* stack_start;
    JsVirtualStack* stack_end;
    JsStaticVal *js_static;
    JsHeap* js_heap;
    uint32_t seed;
} JSRT_CTX;

JSRT_CTX* JSRT_NewCtx();
void JSRT_FreeCtx(JSRT_CTX* ctx);

JS_VAL JSRT_NewUndefined(JSRT_CTX* ctx, JS_TY_FLAGS flags);
JS_VAL JSRT_NewBool(JSRT_CTX* ctx, JS_TY_FLAGS flags, int val);
JS_VAL JSRT_NewI32(JSRT_CTX* ctx, int32_t value);
JS_VAL JSRT_NewDouble(JSRT_CTX* ctx, double value);
JS_VAL JSRT_NewNaN(JSRT_CTX* ctx);
JS_VAL JSRT_NewStrUTF8Auto(JSRT_CTX* ctx, JS_TY_FLAGS flags, const char* utf8);
JS_VAL JSRT_NewStrUTF8(JSRT_CTX* ctx, JS_TY_FLAGS flags, const uint8_t* utf8, uint32_t str_size);
int JSRT_StdStrToUTF8(JSRT_CTX* ctx, JS_VAL val, uint8_t* bytes, uint32_t size);

JS_VAL JSRT_NewArray(JSRT_CTX* ctx, JS_TY_FLAGS flags, uint32_t cap);

JS_VAL JSRT_NewStdObject(JSRT_CTX* ctx, JS_TY_FLAGS flags);

JS_VAL JSRT_NewFunction(JSRT_CTX* ctx, JSRT_RawFunction raw, JsFunClosureEnv* env);

JsVirtualStack* JSRT_NewVirtualStack(JSRT_CTX* ctx, const char* name, JS_VAL arg, uint32_t var_size);
JsVirtualStack* JSRT_NewVirtualStack2(JSRT_CTX* ctx, const char* name, JS_VAL arg, uint32_t var_size, JsVirtualStack* prev);
void JSRT_ReleaseVirtualStack(struct JSRT_CTX*ctx, JsVirtualStack* st);

JS_VAL JSRT_StrictEq(JSRT_CTX* ctx, JS_VAL val1, JS_VAL val2);
JS_VAL JSRT_ValAdd(JSRT_CTX* ctx, JS_VAL val1, JS_VAL val2);

uint32_t JSRT_SimpleHash(const JS_TY_CHAR *str, size_t l, uint32_t seed);

JS_VAL JSRT_TypeOf(JSRT_CTX* ctx, JS_VAL val);

JS_TY_RC JSRT_GetRetainCount(JS_VAL val);
JS_VAL JSRT_Retain(JSRT_CTX* ctx, JS_VAL val);
void JSRT_Release(JSRT_CTX* ctx, JS_VAL val);

static int JSRT_Errno;

#endif //JSRT
