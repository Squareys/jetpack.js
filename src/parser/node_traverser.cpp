/* Generated by Racket Script! */

#include "node_traverser.h"
#include <memory>

void NodeTraverser::TraverseNodeBefore_(const Sp<SyntaxNode> &node) {
    switch (node->type) {
        case SyntaxNodeType::ArrayExpression: {
            auto child = std::dynamic_pointer_cast<ArrayExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->elements.rbegin(); i != child->elements.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::ArrayPattern: {
            auto child = std::dynamic_pointer_cast<ArrayPattern>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->elements.rbegin(); i != child->elements.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::ArrowFunctionExpression: {
            auto child = std::dynamic_pointer_cast<ArrowFunctionExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            for (auto i = child->params.rbegin(); i != child->params.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::AssignmentExpression: {
            auto child = std::dynamic_pointer_cast<AssignmentExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->right);
            Push(child->left);
            break;
        }

        case SyntaxNodeType::AssignmentPattern: {
            auto child = std::dynamic_pointer_cast<AssignmentPattern>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->right);
            Push(child->left);
            break;
        }

        case SyntaxNodeType::AsyncArrowFunctionExpression: {
            auto child = std::dynamic_pointer_cast<AsyncArrowFunctionExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            for (auto i = child->params.rbegin(); i != child->params.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::AsyncFunctionDeclaration: {
            auto child = std::dynamic_pointer_cast<AsyncFunctionDeclaration>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            for (auto i = child->params.rbegin(); i != child->params.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::AsyncFunctionExpression: {
            auto child = std::dynamic_pointer_cast<AsyncFunctionExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            for (auto i = child->params.rbegin(); i != child->params.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::AwaitExpression: {
            auto child = std::dynamic_pointer_cast<AwaitExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->argument);
            break;
        }

        case SyntaxNodeType::BinaryExpression: {
            auto child = std::dynamic_pointer_cast<BinaryExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->right);
            Push(child->left);
            break;
        }

        case SyntaxNodeType::BlockStatement: {
            auto child = std::dynamic_pointer_cast<BlockStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->body.rbegin(); i != child->body.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::BreakStatement: {
            auto child = std::dynamic_pointer_cast<BreakStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        case SyntaxNodeType::CallExpression: {
            auto child = std::dynamic_pointer_cast<CallExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->arguments.rbegin(); i != child->arguments.rend(); i++) {
                Push(*i);
            }
            Push(child->callee);
            break;
        }

        case SyntaxNodeType::CatchClause: {
            auto child = std::dynamic_pointer_cast<CatchClause>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            Push(child->param);
            break;
        }

        case SyntaxNodeType::ClassBody: {
            auto child = std::dynamic_pointer_cast<ClassBody>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->body.rbegin(); i != child->body.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::ClassDeclaration: {
            auto child = std::dynamic_pointer_cast<ClassDeclaration>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            break;
        }

        case SyntaxNodeType::ClassExpression: {
            auto child = std::dynamic_pointer_cast<ClassExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        case SyntaxNodeType::ComputedMemberExpression: {
            auto child = std::dynamic_pointer_cast<ComputedMemberExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->property);
            Push(child->object);
            break;
        }

        case SyntaxNodeType::ConditionalExpression: {
            auto child = std::dynamic_pointer_cast<ConditionalExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->alternate);
            Push(child->consequent);
            Push(child->test);
            break;
        }

        case SyntaxNodeType::ContinueStatement: {
            auto child = std::dynamic_pointer_cast<ContinueStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        case SyntaxNodeType::DebuggerStatement: {
            auto child = std::dynamic_pointer_cast<DebuggerStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        case SyntaxNodeType::Directive: {
            auto child = std::dynamic_pointer_cast<Directive>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->expression);
            break;
        }

        case SyntaxNodeType::DoWhileStatement: {
            auto child = std::dynamic_pointer_cast<DoWhileStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->test);
            Push(child->body);
            break;
        }

        case SyntaxNodeType::EmptyStatement: {
            auto child = std::dynamic_pointer_cast<EmptyStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        case SyntaxNodeType::ExportAllDeclaration: {
            auto child = std::dynamic_pointer_cast<ExportAllDeclaration>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->source);
            break;
        }

        case SyntaxNodeType::ExportDefaultDeclaration: {
            auto child = std::dynamic_pointer_cast<ExportDefaultDeclaration>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->declaration);
            break;
        }

        case SyntaxNodeType::ExportNamedDeclaration: {
            auto child = std::dynamic_pointer_cast<ExportNamedDeclaration>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->specifiers.rbegin(); i != child->specifiers.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::ExportSpecifier: {
            auto child = std::dynamic_pointer_cast<ExportSpecifier>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->local);
            Push(child->exported);
            break;
        }

        case SyntaxNodeType::ExpressionStatement: {
            auto child = std::dynamic_pointer_cast<ExpressionStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->expression);
            break;
        }

        case SyntaxNodeType::ForInStatement: {
            auto child = std::dynamic_pointer_cast<ForInStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            Push(child->right);
            Push(child->left);
            break;
        }

        case SyntaxNodeType::ForOfStatement: {
            auto child = std::dynamic_pointer_cast<ForOfStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            Push(child->right);
            Push(child->left);
            break;
        }

        case SyntaxNodeType::ForStatement: {
            auto child = std::dynamic_pointer_cast<ForStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            break;
        }

        case SyntaxNodeType::FunctionDeclaration: {
            auto child = std::dynamic_pointer_cast<FunctionDeclaration>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            for (auto i = child->params.rbegin(); i != child->params.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::FunctionExpression: {
            auto child = std::dynamic_pointer_cast<FunctionExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            for (auto i = child->params.rbegin(); i != child->params.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::Identifier: {
            auto child = std::dynamic_pointer_cast<Identifier>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        case SyntaxNodeType::IfStatement: {
            auto child = std::dynamic_pointer_cast<IfStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->consequent);
            Push(child->test);
            break;
        }

        case SyntaxNodeType::Import: {
            auto child = std::dynamic_pointer_cast<Import>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        case SyntaxNodeType::ImportDeclaration: {
            auto child = std::dynamic_pointer_cast<ImportDeclaration>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->source);
            for (auto i = child->specifiers.rbegin(); i != child->specifiers.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::ImportDefaultSpecifier: {
            auto child = std::dynamic_pointer_cast<ImportDefaultSpecifier>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->local);
            break;
        }

        case SyntaxNodeType::ImportNamespaceSpecifier: {
            auto child = std::dynamic_pointer_cast<ImportNamespaceSpecifier>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->local);
            break;
        }

        case SyntaxNodeType::ImportSpecifier: {
            auto child = std::dynamic_pointer_cast<ImportSpecifier>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->imported);
            Push(child->local);
            break;
        }

        case SyntaxNodeType::LabeledStatement: {
            auto child = std::dynamic_pointer_cast<LabeledStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            Push(child->label);
            break;
        }

        case SyntaxNodeType::Literal: {
            auto child = std::dynamic_pointer_cast<Literal>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        case SyntaxNodeType::MetaProperty: {
            auto child = std::dynamic_pointer_cast<MetaProperty>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->property);
            Push(child->meta);
            break;
        }

        case SyntaxNodeType::MethodDefinition: {
            auto child = std::dynamic_pointer_cast<MethodDefinition>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        case SyntaxNodeType::Module: {
            auto child = std::dynamic_pointer_cast<Module>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->body.rbegin(); i != child->body.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::NewExpression: {
            auto child = std::dynamic_pointer_cast<NewExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->arguments.rbegin(); i != child->arguments.rend(); i++) {
                Push(*i);
            }
            Push(child->callee);
            break;
        }

        case SyntaxNodeType::ObjectExpression: {
            auto child = std::dynamic_pointer_cast<ObjectExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->properties.rbegin(); i != child->properties.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::ObjectPattern: {
            auto child = std::dynamic_pointer_cast<ObjectPattern>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->properties.rbegin(); i != child->properties.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::Property: {
            auto child = std::dynamic_pointer_cast<Property>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->key);
            break;
        }

        case SyntaxNodeType::RegexLiteral: {
            auto child = std::dynamic_pointer_cast<RegexLiteral>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        case SyntaxNodeType::RestElement: {
            auto child = std::dynamic_pointer_cast<RestElement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->argument);
            break;
        }

        case SyntaxNodeType::ReturnStatement: {
            auto child = std::dynamic_pointer_cast<ReturnStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        case SyntaxNodeType::Script: {
            auto child = std::dynamic_pointer_cast<Script>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->body.rbegin(); i != child->body.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::SequenceExpression: {
            auto child = std::dynamic_pointer_cast<SequenceExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->expressions.rbegin(); i != child->expressions.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::SpreadElement: {
            auto child = std::dynamic_pointer_cast<SpreadElement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->argument);
            break;
        }

        case SyntaxNodeType::StaticMemberExpression: {
            auto child = std::dynamic_pointer_cast<StaticMemberExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->property);
            Push(child->object);
            break;
        }

        case SyntaxNodeType::Super: {
            auto child = std::dynamic_pointer_cast<Super>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        case SyntaxNodeType::SwitchCase: {
            auto child = std::dynamic_pointer_cast<SwitchCase>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->consequent.rbegin(); i != child->consequent.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::SwitchStatement: {
            auto child = std::dynamic_pointer_cast<SwitchStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->cases.rbegin(); i != child->cases.rend(); i++) {
                Push(*i);
            }
            Push(child->discrimiant);
            break;
        }

        case SyntaxNodeType::TaggedTemplateExpression: {
            auto child = std::dynamic_pointer_cast<TaggedTemplateExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->quasi);
            Push(child->tag);
            break;
        }

        case SyntaxNodeType::TemplateElement: {
            auto child = std::dynamic_pointer_cast<TemplateElement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->expressions.rbegin(); i != child->expressions.rend(); i++) {
                Push(*i);
            }
            for (auto i = child->quasis.rbegin(); i != child->quasis.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::ThisExpression: {
            auto child = std::dynamic_pointer_cast<ThisExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        case SyntaxNodeType::ThrowStatement: {
            auto child = std::dynamic_pointer_cast<ThrowStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->argument);
            break;
        }

        case SyntaxNodeType::TryStatement: {
            auto child = std::dynamic_pointer_cast<TryStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->block);
            break;
        }

        case SyntaxNodeType::UnaryExpression: {
            auto child = std::dynamic_pointer_cast<UnaryExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->argument);
            break;
        }

        case SyntaxNodeType::UpdateExpression: {
            auto child = std::dynamic_pointer_cast<UpdateExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->argument);
            break;
        }

        case SyntaxNodeType::VariableDeclaration: {
            auto child = std::dynamic_pointer_cast<VariableDeclaration>(node);
            if(!traverser_->TraverseBefore(child)) return;
            for (auto i = child->declarations.rbegin(); i != child->declarations.rend(); i++) {
                Push(*i);
            }
            break;
        }

        case SyntaxNodeType::VariableDeclarator: {
            auto child = std::dynamic_pointer_cast<VariableDeclarator>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->id);
            break;
        }

        case SyntaxNodeType::WhileStatement: {
            auto child = std::dynamic_pointer_cast<WhileStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            Push(child->test);
            break;
        }

        case SyntaxNodeType::WithStatement: {
            auto child = std::dynamic_pointer_cast<WithStatement>(node);
            if(!traverser_->TraverseBefore(child)) return;
            Push(child->body);
            Push(child->object);
            break;
        }

        case SyntaxNodeType::YieldExpression: {
            auto child = std::dynamic_pointer_cast<YieldExpression>(node);
            if(!traverser_->TraverseBefore(child)) return;
            break;
        }

        default:
            break;

    }
    
}
void NodeTraverser::TraverseNodeAfter_(const Sp<SyntaxNode> &node) {
    switch (node->type) {
        case SyntaxNodeType::ArrayExpression: {
            auto child = std::dynamic_pointer_cast<ArrayExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ArrayPattern: {
            auto child = std::dynamic_pointer_cast<ArrayPattern>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ArrowFunctionExpression: {
            auto child = std::dynamic_pointer_cast<ArrowFunctionExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::AssignmentExpression: {
            auto child = std::dynamic_pointer_cast<AssignmentExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::AssignmentPattern: {
            auto child = std::dynamic_pointer_cast<AssignmentPattern>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::AsyncArrowFunctionExpression: {
            auto child = std::dynamic_pointer_cast<AsyncArrowFunctionExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::AsyncFunctionDeclaration: {
            auto child = std::dynamic_pointer_cast<AsyncFunctionDeclaration>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::AsyncFunctionExpression: {
            auto child = std::dynamic_pointer_cast<AsyncFunctionExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::AwaitExpression: {
            auto child = std::dynamic_pointer_cast<AwaitExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::BinaryExpression: {
            auto child = std::dynamic_pointer_cast<BinaryExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::BlockStatement: {
            auto child = std::dynamic_pointer_cast<BlockStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::BreakStatement: {
            auto child = std::dynamic_pointer_cast<BreakStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::CallExpression: {
            auto child = std::dynamic_pointer_cast<CallExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::CatchClause: {
            auto child = std::dynamic_pointer_cast<CatchClause>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ClassBody: {
            auto child = std::dynamic_pointer_cast<ClassBody>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ClassDeclaration: {
            auto child = std::dynamic_pointer_cast<ClassDeclaration>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ClassExpression: {
            auto child = std::dynamic_pointer_cast<ClassExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ComputedMemberExpression: {
            auto child = std::dynamic_pointer_cast<ComputedMemberExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ConditionalExpression: {
            auto child = std::dynamic_pointer_cast<ConditionalExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ContinueStatement: {
            auto child = std::dynamic_pointer_cast<ContinueStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::DebuggerStatement: {
            auto child = std::dynamic_pointer_cast<DebuggerStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::Directive: {
            auto child = std::dynamic_pointer_cast<Directive>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::DoWhileStatement: {
            auto child = std::dynamic_pointer_cast<DoWhileStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::EmptyStatement: {
            auto child = std::dynamic_pointer_cast<EmptyStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ExportAllDeclaration: {
            auto child = std::dynamic_pointer_cast<ExportAllDeclaration>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ExportDefaultDeclaration: {
            auto child = std::dynamic_pointer_cast<ExportDefaultDeclaration>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ExportNamedDeclaration: {
            auto child = std::dynamic_pointer_cast<ExportNamedDeclaration>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ExportSpecifier: {
            auto child = std::dynamic_pointer_cast<ExportSpecifier>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ExpressionStatement: {
            auto child = std::dynamic_pointer_cast<ExpressionStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ForInStatement: {
            auto child = std::dynamic_pointer_cast<ForInStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ForOfStatement: {
            auto child = std::dynamic_pointer_cast<ForOfStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ForStatement: {
            auto child = std::dynamic_pointer_cast<ForStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::FunctionDeclaration: {
            auto child = std::dynamic_pointer_cast<FunctionDeclaration>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::FunctionExpression: {
            auto child = std::dynamic_pointer_cast<FunctionExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::Identifier: {
            auto child = std::dynamic_pointer_cast<Identifier>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::IfStatement: {
            auto child = std::dynamic_pointer_cast<IfStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::Import: {
            auto child = std::dynamic_pointer_cast<Import>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ImportDeclaration: {
            auto child = std::dynamic_pointer_cast<ImportDeclaration>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ImportDefaultSpecifier: {
            auto child = std::dynamic_pointer_cast<ImportDefaultSpecifier>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ImportNamespaceSpecifier: {
            auto child = std::dynamic_pointer_cast<ImportNamespaceSpecifier>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ImportSpecifier: {
            auto child = std::dynamic_pointer_cast<ImportSpecifier>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::LabeledStatement: {
            auto child = std::dynamic_pointer_cast<LabeledStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::Literal: {
            auto child = std::dynamic_pointer_cast<Literal>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::MetaProperty: {
            auto child = std::dynamic_pointer_cast<MetaProperty>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::MethodDefinition: {
            auto child = std::dynamic_pointer_cast<MethodDefinition>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::Module: {
            auto child = std::dynamic_pointer_cast<Module>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::NewExpression: {
            auto child = std::dynamic_pointer_cast<NewExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ObjectExpression: {
            auto child = std::dynamic_pointer_cast<ObjectExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ObjectPattern: {
            auto child = std::dynamic_pointer_cast<ObjectPattern>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::Property: {
            auto child = std::dynamic_pointer_cast<Property>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::RegexLiteral: {
            auto child = std::dynamic_pointer_cast<RegexLiteral>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::RestElement: {
            auto child = std::dynamic_pointer_cast<RestElement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ReturnStatement: {
            auto child = std::dynamic_pointer_cast<ReturnStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::Script: {
            auto child = std::dynamic_pointer_cast<Script>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::SequenceExpression: {
            auto child = std::dynamic_pointer_cast<SequenceExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::SpreadElement: {
            auto child = std::dynamic_pointer_cast<SpreadElement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::StaticMemberExpression: {
            auto child = std::dynamic_pointer_cast<StaticMemberExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::Super: {
            auto child = std::dynamic_pointer_cast<Super>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::SwitchCase: {
            auto child = std::dynamic_pointer_cast<SwitchCase>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::SwitchStatement: {
            auto child = std::dynamic_pointer_cast<SwitchStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::TaggedTemplateExpression: {
            auto child = std::dynamic_pointer_cast<TaggedTemplateExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::TemplateElement: {
            auto child = std::dynamic_pointer_cast<TemplateElement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ThisExpression: {
            auto child = std::dynamic_pointer_cast<ThisExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::ThrowStatement: {
            auto child = std::dynamic_pointer_cast<ThrowStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::TryStatement: {
            auto child = std::dynamic_pointer_cast<TryStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::UnaryExpression: {
            auto child = std::dynamic_pointer_cast<UnaryExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::UpdateExpression: {
            auto child = std::dynamic_pointer_cast<UpdateExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::VariableDeclaration: {
            auto child = std::dynamic_pointer_cast<VariableDeclaration>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::VariableDeclarator: {
            auto child = std::dynamic_pointer_cast<VariableDeclarator>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::WhileStatement: {
            auto child = std::dynamic_pointer_cast<WhileStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::WithStatement: {
            auto child = std::dynamic_pointer_cast<WithStatement>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        case SyntaxNodeType::YieldExpression: {
            auto child = std::dynamic_pointer_cast<YieldExpression>(node);
            traverser_->TraverseAfter(child);
            break;
        }

        default:
            break;

    }
    
}
