require 'securerandom'
class TreeNode
  attr_accessor :data, :first_child, :next_sibling
  def initialize(data)
    @data = data
    @seed = SecureRandom
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
# tree.show
# -------------------------
# 6-36
# -------------------------
def get_sum(node)
  return 0 if node.nil?
  return node.data + get_sum(node.first_child) + get_sum(node.next_sibling)
end

puts get_sum(tree)
