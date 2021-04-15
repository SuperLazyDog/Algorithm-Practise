require 'securerandom'
class TreeNode
  attr_accessor :data, :first_child, :next_sibling
  def initialize(data)
    @data = data
  end

  def show
    puts "show tree"
    _show(self)
    puts ""
  end

  def self.build_tree(ary)
    return if ary.empty?
    data = ary.shift
    node = TreeNode.new(data)
    if SecureRandom.random_number(2) == 1
      node.next_sibling = build_tree(ary)
    else
      node.first_child = build_tree(ary)
    end
    return node
  end

  private
  def _show(node)
    return if node.nil?
    print "#{node.data}\t"
    if !node.next_sibling.nil?
      _show(node.next_sibling)
    end
    if !node.first_child.nil?
      puts "\n"
      _show(node.first_child)
    end
  end
end


tree = TreeNode.build_tree((1..100).to_a)
tree.show
# -------------------------
# 6-43
# -------------------------
def is_quasi_isomorphic(tree1, tree2)
  return true if tree1.nil? && tree2.nil?
  return false if [tree1, tree2].compact.count == 1
  return (is_quasi_isomorphic(tree1.first_child, tree2.first_child) && is_quasi_isomorphic(tree1.next_sibling, tree2.next_sibling)) ||
    (is_quasi_isomorphic(tree1.first_child, tree2.next_sibling) && is_quasi_isomorphic(tree1.next_sibling, tree2.first_child))
end

puts "is_quasi_isomorphic: #{is_quasi_isomorphic(tree, tree)}"
quasi_tree = TreeNode.new(123)
quasi_tree.first_child = tree.next_sibling
quasi_tree.next_sibling = tree.first_child
puts "is_quasi_isomorphic: #{is_quasi_isomorphic(tree, quasi_tree)}"
