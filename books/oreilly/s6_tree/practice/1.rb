class BinaryTree
  attr_reader :right, :left, :data
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
    puts "data: #{@data}, left->data: #{@left && @left.data}, right->data: #{@right && @right.data}"
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

MIN = -1
# -------------------------
# 6-1
# -------------------------
# 自己搞的
# def find_max(node) # 默认大于0
#   return MIN if node == nil
#   if node.right.nil? && node.left.nil?
#     return node.data
#   elsif node.right.nil?
#     return [find_max(node.left), MIN, node.data].max
#   elsif node.left.nil?# the left is nil
#     return [MIN, find_max(node.right), node.data].max
#   else
#     return [find_max(node.left), find_max(node.right), node.data].max
#   end
# end
# 参考书上p133
# def find_max(node)
#   return MIN if node.nil?
#   left = find_max(node.left)
#   right = find_max(node.right)
#   return [left, right, node.data].max
# end




# -------------------------
# 6-2
# -------------------------
# 不用递归
def find_max(node)
  return MIN if node.nil?
  queue = [node]
  max = MIN
  while !queue.empty?
    cur = queue.shift
    max = [cur.data, max].max
    queue.push cur.left unless cur.left.nil?
    queue.push cur.right unless cur.right.nil?
  end
  return max
end
puts find_max(a)
