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
# 6-14
# -------------------------
# def get_leaves_number(node)
#   return 0 if node.nil?
#   return 1 if node.left.nil? && node.right.nil?
#   return get_leaves_number(node.left) + get_leaves_number(node.right)
# end

# 非递归
def get_leaves_number(node)
  return 0 if node.nil?
  tmp = 0
  queue = [node]
  while !queue.empty?
    cur = queue.shift
    if cur.left.nil? && cur.right.nil?
      tmp += 1
    end
    queue.push cur.left if !cur.left.nil?
    queue.push cur.right if !cur.right.nil?
  end
  return tmp
end

puts get_leaves_number(a)
