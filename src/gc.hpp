//
// Created by Duzhong Chen on 2019/9/3.
//

#pragma once

#include <cinttypes>
#include <utility>
#include <list>
#include <functional>

class GarbageCollector final {
public:

    GarbageCollector() = default;
    GarbageCollector(const GarbageCollector&) = delete;
    GarbageCollector(GarbageCollector&&) = delete;

    class ObjectHeader;

    typedef std::function<void(ObjectHeader*)> MarkFunction;

    class ObjectHeader {
    public:
        std::uint8_t gc_mark_;

        inline void ClearMark();
        inline void Mark();
        inline bool HasMark() const;

        virtual void MarkChildren(MarkFunction marker) {};

        virtual ~ObjectHeader() = default;
    };

    template <typename DT>
    class BoxPtr: ObjectHeader {
    public:
        BoxPtr(DT*);
        DT* get() const;

    private:
        DT* de_ptr = nullptr;

    };

    template <typename DT>
    class Ptr {
    public:
        Ptr(BoxPtr<DT>*);
        DT* get() const;

        BoxPtr<DT>* get_box_ptr() const { return box_ptr_; }

    private:
        BoxPtr<DT>* box_ptr_ = nullptr;

    };

    template<typename T, typename ...Args>
    T* Alloc(Args && ...args);

    template<typename T, typename ...Args>
    Ptr<T> MakePtr(Args && ...args);

    void MarkAndSweep();

    ~GarbageCollector() {
        for (auto obj : data_) {
            delete obj;
        }
    }

private:
    std::list<ObjectHeader*> data_;
    std::uint32_t allocated_space_ = 0u;

};

inline void GarbageCollector::ObjectHeader::ClearMark() {
    gc_mark_ &= ((~ 0u) << 1u);
}

inline void GarbageCollector::ObjectHeader::Mark() {
    gc_mark_ |= 1u;
}

inline bool GarbageCollector::ObjectHeader::HasMark() const {
    return gc_mark_ & 1u;
}

template<typename T, typename ...Args>
T* GarbageCollector::Alloc(Args &&... args) {
    static_assert(std::is_base_of<ObjectHeader, T>::value, "T not derived from ObjectHeader");

    T* result = new T(std::forward<Args>(args)...);

    std::uint32_t size_ = sizeof(T);
    allocated_space_ += size_;

    data_.push_back(result);
    return result;
}

template<typename T, typename ...Args>
GarbageCollector::Ptr<T> GarbageCollector::MakePtr(Args &&... args) {
    BoxPtr<T>* box_ptr = Alloc<BoxPtr>(std::forward<Args>(args)...);
    return Ptr(box_ptr);
}
