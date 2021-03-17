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
# 6-10
# -------------------------
# def get_height(node)
#   return 0 if node.nil?
#   return [get_height(node.left), get_height(node.right)].max + 1
# end

# -------------------------
# 6-11 非再帰
# -------------------------
# def get_height(node)
#   return 0 if node.nil?
#   max = 0
#   queue = [{node: node, level: 1}]
#   while !queue.empty?
#     cur_info = queue.shift
#     cur = cur_info[:node]
#     if max < cur_info[:level]
#       max = cur_info[:level]
#     end
#     if !cur.left.nil?
#       queue.push({
#         node: cur.left,
#         level: cur_info[:level] + 1
#       })
#     end
#     if !cur.right.nil?
#       queue.push({
#         node: cur.right,
#         level: cur_info[:level] + 1
#       })
#     end
#   end
#   return max
# end

# 模範回答
# [1, null, 2, 3, null, 4, 5, 6, 7, null, ...]
def get_height(node)
  return 0 if node.nil?
  level = 0 # 书上有误, 这里应是0.
  queue = [node, nil]
  while !queue.empty?
    cur = queue.shift
    if cur.nil?
      level += 1
      if !queue.empty?
        queue.push nil
      end
      next
    end
    queue.push cur.left if !cur.left.nil?
    queue.push cur.right if !cur.right.nil?
  end
  return level
end

puts get_height(a)
