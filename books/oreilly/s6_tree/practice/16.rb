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
# -------------------------
# 6-16
# -------------------------
# def get_half_nodes_count(node)
#   return 0 if node.nil?
#   tmp = 0
#   if [node.left, node.right].compact.length == 1
#     tmp = 1
#   end
#   return get_half_nodes_count(node.left) + tmp + get_half_nodes_count(node.right)
# end

# 非再帰
def get_half_nodes_count(node)
  return 0 if node.nil?
  queue = [node]
  tmp = 0
  while !queue.empty?
    cur = queue.pop
    if [cur.left, cur.right].compact.length == 1
      tmp += 1
    end
    queue.push cur.left if !cur.left.nil?
    queue.push cur.right if !cur.right.nil?
  end
  return tmp
end
puts get_half_nodes_count(a)
