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
# 6-44
# -------------------------
# A B E F G C I J K D
# 1 2 3 4 5 6 7 8 9 10
# TODO: weida finish here
def build_k_tree
end