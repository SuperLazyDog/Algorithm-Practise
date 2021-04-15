class BinaryTree
  attr_accessor :right, :left, :data
  # attr_accessor :data
  def initialize(data = nil)
    @right = nil
    @left = nil
    @data = data
  end

  def generate(data:, side:)
    if side == :left
      @left = BinaryTree.new(data)
    else
      @right = BinaryTree.new(data)
    end
  end

  def show
    queue = []
    queue.push self
    queue.push nil
    while !queue.empty?
      cur = queue.shift
      if cur.nil?
        if !queue.empty?
          printf "\n"
          queue.push nil
        end
      else
        printf "%d\t", cur.data
        queue.push cur.left if !cur.left.nil?
        queue.push cur.right if !cur.right.nil?
      end
    end
    puts ""
  end
end

#                 1
#         2                3
#    4     5           6       7
a = BinaryTree.new(1)
a.generate(data: 2, side: :left)
a.generate(data: 3, side: :right)
a.left.generate(data: 4, side: :left)
a.left.generate(data: 5, side: :right)
a.right.generate(data: 6, side: :left)
a.right.generate(data: 7, side: :right)
# a.show
# a.left.show
# a.right.show
# -------------------------
# 6-26
# -------------------------
# 最小祖先
# def get_least_common_ancestor(node, c1, c2)
#   return nil if node.nil?
#   return node if node == c1 || node == c2
#   left = get_least_common_ancestor(node.left, c1, c2)
#   right = get_least_common_ancestor(node.right, c1, c2)
#   return node if !left.nil? && !right.nil?
#   return left || right
# end

# 2021-4-16自己想的
# 总结: 注意数据类型, c1, c2 是 node, 不是 数值
def get_least_common_ancestor(node, c1, c2)
  return nil if node.nil?
  return node if node.data == c1.data || node.data == c2.data
  left = get_least_common_ancestor(node.left, c1, c2)
  right = get_least_common_ancestor(node.right, c1, c2)
  if !left.nil? && !right.nil?
    return node
  elsif left.nil? && right.nil?
    return nil
  else
    return left.nil? ? right : left
  end
end

puts get_least_common_ancestor(a, a.left.right, a.left.left).show
