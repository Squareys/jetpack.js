require './syntax_def'

def print_title
  puts "/* Generated by Ruby Script! */"
end

class Symbol

  def to_codegen
    if self == :String then
      return "UString"
    elsif self == :Boolean then
      return "bool"
    elsif self == :Number then
      return "double"
    elsif self == :VarKind then
      return "VarKind"
    else
      return "Sp<" + self.to_s + ">"
    end
  end

end

class Array

  def to_codegen
    if self.length == 1 and self[0].is_a? Symbol then
      return "std::vector<#{self[0].to_codegen}>"
    end
    super.to_codegen
  end

end


class Option

  def to_codegen
    "std::optional<#{@value.to_codegen}>"
  end

end

class Variant

  def to_codegen
    "std::variant<#{self.str_content}>"
  end

  def str_content
    result = ""
    @elements.each do |item|
      result += item.to_codegen + ", "
    end
    result.slice(0, result.length - 2)
  end

end

class Property


  @@reservec_props = [
    "operator",
    "static",
  ]

  def pretty_name
    result = @name.chars.map do |ch|
      if /[[:upper:]]/.match(ch) then
        ['_', ch.downcase]
      else
        [ch]
      end
    end
    
    result = result.flatten.join('')

    if @@reservec_props.include? result then
      return result + '_'
    end
    result
  end

  def to_codegen
    result = @prop_type.to_codegen + " " + self.pretty_name

    if @prop_type == :Boolean
      result += " = false"
    end

    result
  end

end

$stdout.reopen('src/parser/node_types.h', 'w')

print_title
puts "
#pragma once

enum class SyntaxNodeType {
    Invalid = 0,

"

SyntaxFactory.syntaxes.each do |item|
  if !item.is_virtual then
    puts "    " + item.class_id.to_s + ","
  end
end

puts "
};
"

puts ""
puts "static const char* SyntaxNodeTypeToString(SyntaxNodeType type_);"
puts ""

SyntaxFactory.syntaxes.each do |item|
  if !item.is_virtual then
    puts "class " + item.class_id.to_s + ";"
  end
end

$stdout.reopen('src/parser/syntax_nodes.h', 'w')

print_title
puts '

#pragma once

#include "base_nodes.h"
#include <optional>
#include <vector>
#include <variant>

'

SyntaxFactory.syntaxes.each do |item|
  if !item.is_virtual then
    id = item.class_id.to_s
    puts "
class #{id}: public #{item.base.to_s} {
public:
    #{id}();

"
  item.props.each do |prop|
    puts "    #{prop.to_codegen};"
  end

  puts "
};
"
  end
end

$stdout.reopen('src/parser/syntax_nodes.cpp', 'w')
print_title
puts '
#include "syntax_nodes.h"
'

SyntaxFactory.syntaxes.each do |item|
  if !item.is_virtual then
    id = item.class_id.to_s
    puts "
#{id}::#{id}(): #{item.base.to_s}() {
    type = SyntaxNodeType::#{id};
}
"
  end
end

$stdout.reopen('src/parser/node_types.cpp', 'w')
print_title
puts '
#include "node_types.h"

const char* SyntaxNodeTypeToString(SyntaxNodeType type_) {
    switch (type_) {
'

SyntaxFactory.syntaxes.each do |item|
  if !item.is_virtual then
    id = item.class_id.to_s
    puts "
        case SyntaxNodeType::#{id}:
            return \"#{id}\";
"
  end
end

puts '
        default:
            return "<Invalid>";

    }
}
'

$stdout.reopen('src/parser/node_traverser_intf.h', 'w')
print_title
puts '
#pragma once
#include "syntax_nodes.h"

class INodeTraverser {
public:
'

SyntaxFactory.syntaxes.each do |item|
  if !item.is_virtual then
    id = item.class_id.to_s
    puts "
    virtual bool TraverseBefore(const Sp<#{id}>& node) { return true; }

    virtual void TraverseAfter(const Sp<#{id}>& node) {}
"
  end
end

puts '
};
'

$stdout.reopen('src/parser/node_traverser.cpp', 'w')
print_title
puts '
#include "node_traverser.h"
#include <memory>

void NodeTraverser::TraverseNodeBefore_(const Sp<SyntaxNode> &node) {
    switch (node->type) {
'

SyntaxFactory.syntaxes.each do |item|
  if !item.is_virtual then
    id = item.class_id.to_s
    puts "
        case SyntaxNodeType::#{id}: {
            auto child = std::dynamic_pointer_cast<#{id}>(node);
            if(!traverser_->TraverseBefore(child)) return;"

    item.props.reverse.each do |item|
      if not [:String, :Boolean, :Number, :VarKind].include? item.prop_type then
        if item.prop_type.is_a? Array then

          puts "
            for (auto i = child->#{item.name}.rbegin(); i != child->#{item.name}.rend(); i++) {
                Push(*i);
            }"
        elsif item.prop_type.is_a? Option then
          puts "            if (child->#{item.pretty_name}) {"
          puts "                Push(*child->#{item.pretty_name});"
          puts "            }"
        elsif item.prop_type.is_a? Variant then
          # nothing
        else
          puts "            Push(child->#{item.pretty_name});"
        end
      end
    end

    puts "
            break;
        }
"
  end
end

puts '
        default:
            break;

    }
}

void NodeTraverser::TraverseNodeAfter_(const Sp<SyntaxNode> &node) {
    switch (node->type) {
'


SyntaxFactory.syntaxes.each do |item|
  if !item.is_virtual then
    id = item.class_id.to_s
    puts "
        case SyntaxNodeType::#{id}: {
            auto child = std::dynamic_pointer_cast<#{id}>(node);
            traverser_->TraverseAfter(child);
            break;
        }"

  end
end

puts '
        default:
            break;

    }
}
'

$stdout.reopen('src/dumper/ast_to_json.h', 'w')
print_title
puts '
#pragma once

#include <nlohmann/json.hpp>
#include <vector>
#include <memory>
#include "../parser/node_traverser_intf.h"
#include "../utils.h"

namespace dumper {

    using json = nlohmann::json;

    template <typename T>
    using Sp = std::shared_ptr<T>;

    class AstToJson {
    public:

        static json Dump(const Sp<SyntaxNode>& node) {
            switch (node->type) {'

SyntaxFactory.syntaxes.each do |item|
  if !item.is_virtual then
    id = item.class_id.to_s
    puts "
                case SyntaxNodeType::#{id}: {
                    auto child = std::dynamic_pointer_cast<#{id}>(node);
                    return Dump(child);
                }"

  end
end

puts "
                default:
                    return json::object();

            }
        }
"

SyntaxFactory.syntaxes.each do |item|
  if !item.is_virtual then
    id = item.class_id.to_s
    puts "
        static json Dump(const Sp<#{id}>& node) {
            json result = json::object();
            result[\"type\"] = \"#{id}\";"

    item.props.each do |item|
      if [:Boolean, :Number, :VarKind].include? item.prop_type then
        puts "            result[\"#{item.name}\"] = node->#{item.pretty_name};"
      elsif item.prop_type == :String then
        puts "            result[\"#{item.pretty_name}\"] = utils::To_UTF8(node->#{item.pretty_name});"
      elsif item.prop_type.is_a? Array then
        array_name = "array_#{item.name}"
        puts "            json #{array_name} = json::array();"
        puts "
            for (auto& i : node->#{item.name}) {
                #{array_name}.push_back(Dump(i));
            }"
        puts "            result[\"#{item.name}\"] = std::move(#{array_name});"

      elsif item.prop_type.is_a? Option then
        puts "            if (node->#{item.pretty_name}) {"
        puts "                result[\"#{item.pretty_name}\"] = Dump(*node->#{item.pretty_name});"
        puts "            }"
      elsif item.prop_type.is_a? Variant then
        # nothing
      else
        puts "            result[\"#{item.pretty_name}\"] = Dump(node->#{item.pretty_name});"
      end
    end

    puts "
            return result;
        }"

  end
end

puts '
    };
}
'
