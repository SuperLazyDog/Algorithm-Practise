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


# -------------------------
# 6-3
# -------------------------
# def search(node, value) # 重複がないと仮定
#   return nil if node.nil? # no such node
#   if node.data == value
#     return node
#   else
#     left = search(node.left, value)
#     right = search(node.right, value)
#   end
#   return left || right
# end


# -------------------------
# 6-4 非再帰
# -------------------------
def search(node, value)
  queue = [node]
  while !queue.empty?
    cur = queue.pop
    queue.push cur.left unless cur.left.nil?
    queue.push cur.right unless cur.right.nil?
    return cur if value == cur.data
  end
  return nil
end
(1..8).each do |i|
  tmp = search(a, i)
  puts "node: #{tmp}, data: #{tmp&.data}"
end
