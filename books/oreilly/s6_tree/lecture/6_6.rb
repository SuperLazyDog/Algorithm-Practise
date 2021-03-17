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
a.show
a.left.show
a.right.show






def pre_order(tree, &block) # 1 2 4 5 3 6 7
  return if tree.nil?
  if block_given?
    block.call(tree.data)
  else
    puts "no_block, data: #{tree.data}"
  end
  pre_order(tree.left, &block)
  pre_order(tree.right, &block)
end

def pre_order_no_recursive(tree, &block)
  stack = []
  cur = tree
  while true
    while !cur.nil?
      if block_given?
        block.call(cur.data)
      else
        puts "no_block, data: #{cur.data}"
      end
      stack.push cur
      cur = cur.left
    end
    return if stack.empty?
    cur = stack.pop
    cur = cur.right
  end
end

def in_order(tree, &block) # 4 2 5 1 6 3 7
  return if tree.nil?
  in_order tree.left, &block
  if block_given?
    block.call(tree.data)
  else
    puts "no_block, data: #{tree.data}"
  end
  in_order tree.right, &block
end

def in_order_no_recursive(tree, &block)
  stack = []
  cur = tree
  while true
    while !cur.nil?
      stack.push cur
      cur = cur.left
    end
    return if stack.empty?
    cur = stack.pop
    if block_given?
      block.call cur.data
    else
      puts "no_block, data: #{cur.data}"
    end
    cur = cur.right
  end
end

def post_order(tree, &block) # 4 5 2 6 7 3 1
  return if tree.nil?
  post_order tree.left, &block
  post_order tree.right, &block
  if block_given?
    block.call tree.data
  else
    puts "no_block, data: #{tree.data}"
  end
end


#       1
# nil      3
#         nil nil
# a = BinaryTree.new(1)
# a.generate(data: 3, side: :right)
# TODO: weida 这个虽然理解意思了，但是还是有点晕，以后有时间再过几遍
def post_order_no_recursive(tree, &block)
  stack = []
  cur = tree
  while true
    while !cur.nil?
      stack.push cur
      cur = cur.left
    end
    return if stack.empty?
    if stack.last.right.nil?
      cur = stack.pop
      if block_given?
        block.call(cur.data)
      else
        puts "no_block, data: #{cur.data}"
      end
      while !stack.empty? && stack.last.right == cur
        cur = stack.pop
        if block_given?
          block.call(cur.data)
        else
          puts "no_block, data: #{cur.data}"
        end
      end
    end
    if stack.empty?
      cur = nil
    else
      cur = stack.last.right
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

proc = Proc.new { |i| puts i }

puts "pre_order"
pre_order(a, &proc)
puts "pre_order_no_recursive"
pre_order_no_recursive(a, &proc)

puts "in_order"
in_order(a, &proc)
puts "in_order_no_recursive"
in_order_no_recursive(a, &proc)

puts "post_order"
post_order(a, &proc)
puts "post_order_no_recursive"
post_order_no_recursive(a, &proc)

puts "level_order"
level_order(a, &proc)
