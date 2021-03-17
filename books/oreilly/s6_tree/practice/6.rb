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
# 6-6
# -------------------------
# def get_size(tree) #　これはサイズではなく、高さになっている
#   if tree.nil?
#     return 0
#   else
#     left = get_size(tree.left)
#     right = get_size(tree.right)
#     return [left, right].max + 1
#   end
# end

def get_size(tree)
  return 0 if tree.nil?
  return get_size(tree.left) + get_size(tree.right) + 1
end

# -------------------------
# 6-7 非递归
# -------------------------
# def get_size(tree)
#   stack = []
#   cur = tree
#   size = 0
#   while true
#     while !cur.nil?
#       stack.push cur
#       cur = cur.left
#       size += 1
#     end
#     break if stack.empty?
#     cur = stack.pop
#     cur = cur.right
#   end
#   return size
# end

def get_size(tree)
  queue = [tree].compact
  size = 0
  while !queue.empty?
    size+=1
    cur = queue.shift
    queue.push cur.left if !cur.left.nil?
    queue.push cur.right if !cur.right.nil?
  end
  return size
end
puts get_size(a)
