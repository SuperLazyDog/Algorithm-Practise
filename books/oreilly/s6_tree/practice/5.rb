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
# 6-5
# -------------------------
def insert(node, value)
  if node.nil?
    throw RuntimeError.new("node does not exist")
  end
  queue = [node]
  while !queue.empty?
    cur = queue.pop
    if cur.left.nil?
      cur.left = BinaryTree.new(value)
      return
    else
      queue.push cur.left
    end
    if cur.right.nil?
      cur.right = BinaryTree.new(value)
      return
    else
      queue.push cur.right
    end
  end
end

def level_order(tree, &block)
  queue = [] # push, shift
  queue.push tree
  while !queue.empty?
    node = queue.shift
    queue.push node.left unless node.left.nil?
    queue.push node.right unless node.right.nil?
    if block_given?
      block.call(node.data)
    else
      puts "no_block, data: #{node.data}"
    end
  end
end

insert(a, 100)
level_order(a) {|i| puts i}
b = nil
insert(b, 100)
level_order(b) {|i| puts i}
