class BinaryTree
  attr_accessor :right, :left, :data, :next_sibling
  # attr_accessor :data
  def initialize(data = nil)
    @right = nil
    @left = nil
    @next_sibling = nil
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
        printf "%s\t", cur.data
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
# 6-34
# -------------------------
# def fill_next_sibling(node)
#   return if node.nil?
#   queue = [node, nil]
#   while !queue.empty?
#     cur = queue.shift
#     if cur.nil?
#       queue.push nil if !queue.empty?
#     else
#       cur.next_sibling = queue.first
#       queue.push cur.left if !cur.left.nil?
#       queue.push cur.right if !cur.right.nil?
#     end
#   end
# end
# 递归版
def fill_next_sibling(node)
  return if node.nil?
  if !node.left.nil?
    node.left.next_sibling = node.right
  end
  if !node.right.nil?
    node.right.next_sibling = node.next_sibling&.left
  end
  fill_next_sibling(node.left)
  fill_next_sibling(node.right)
end

fill_next_sibling(a)
puts a.inspect
puts a.left.inspect
puts a.right.inspect
