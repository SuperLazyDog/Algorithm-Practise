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
# 6-22
# -------------------------
# def get_sum(node)
#   return 0 if node.nil?
#   return node.data + get_sum(node.left) + get_sum(node.right)
# end

# 非递归
def get_sum(node)
  stack = []
  sum = 0
  while true
    while !node.nil?
      sum += node.data
      stack.push node
      node = node.left
    end
    return sum if stack.empty?
    node = stack.pop.right
  end
end
puts get_sum(a)
