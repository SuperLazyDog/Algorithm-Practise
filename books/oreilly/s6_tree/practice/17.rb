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
# 6-17
# -------------------------
def are_structural_same?(node1, node2)
  return true if node1.nil? && node2.nil?
  return false if [node1, node2].compact.count < 2 || (node1.data != node2.data)
  return are_structural_same?(node1.left, node2.left) && are_structural_same?(node1.right, node2.right)
end



b = BinaryTree.new(1)
b.generate(data: 2, side: :left)
b.generate(data: 3, side: :right)
b.left.generate(data: 4, side: :left)
b.left.generate(data: 5, side: :right)
b.right.generate(data: 6, side: :left)
b.right.generate(data: 7, side: :right)
b.right.right.generate(data: 9, side: :right)
a.show
b.show
puts "are_structural_same? #{are_structural_same?(a, b)}"
