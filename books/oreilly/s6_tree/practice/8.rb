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
# 6-8
# -------------------------
# def reversed_level_order(tree) # 参考の回答はこれで完全な逆順になっていて正しくない
#   queue = [tree].compact
#   stack = []
#   while !queue.empty?
#     cur = queue.shift
#     queue.push cur.left if !cur.left.nil?
#     queue.push cur.right if !cur.right.nil?
#     stack.push cur
#   end
#   while !stack.empty?
#     puts stack.pop.data
#   end
# end

def reversed_level_order(tree)
  return if tree.nil?
  queue = [{node: tree, level: 0}].compact
  ary = [[tree]]
  while !queue.empty?
    cur_info = queue.shift
    cur = cur_info[:node]
    if !cur.left.nil?
      left = {
        node: cur.left,
        level: cur_info[:level]+1
      }
      queue.push left
      ary[left[:level]] = [] if ary[left[:level]].nil?
      ary[left[:level]].push left[:node]
    end
    if !cur.right.nil?
      right = {
        node: cur.right,
        level: cur_info[:level]+1
      }
      queue.push right
      ary[right[:level]] = [] if ary[right[:level]].nil?
      ary[right[:level]].push right[:node]
    end
  end
  ary.reverse.each do |level|
    level.each do |node|
      puts node.data
    end
  end
end

reversed_level_order(a)
