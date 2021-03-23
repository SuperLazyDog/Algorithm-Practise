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
# 6-26
# -------------------------

#             A
#     B               C
#  D    E         F
# pre_order: A B D E C F
# in_order: D B E A F C
# post_order: D E B F C A
# level_order: A B C D E F
def build_tree(pre_order, in_order, s = 0, e = nil)
  # puts "pre_order: #{pre_order}, s: #{s}, e: #{e}"
  e = in_order.count-1 if e.nil?
  return nil if pre_order.empty?
  return nil if e < s
  new_node = BinaryTree.new(pre_order.shift)
  i = in_order.index new_node.data
  new_node.left = build_tree(pre_order, in_order, s, i-1)
  new_node.right = build_tree(pre_order, in_order, i+1, e)
  return new_node
end


def build_tree_post_order(post_order, in_order, s = 0, e = nil)
  e = in_order.count-1 if e.nil?
  return nil if post_order.empty?
  return nil if s > e
  new_node = BinaryTree.new post_order.pop
  i = in_order.index new_node.data
  new_node.right = build_tree_post_order(post_order, in_order, i+1, e)
  new_node.left = build_tree_post_order(post_order, in_order, s, i-1)
  return new_node
end

#  TODO: weida level_order和in_order构建树
# def build_tree_level_order(level_order, in_order)
#   return nil if level_order.empty?
#   root = BinaryTree.new level_order.pop
#   queue = [root, nil]
#   while !level_order.empty?
#     cur = level_order.shift
#
#   end
# end
pre_order = %w(A B D E C F)
in_order = %w(D B E A F C)
post_order = %w(D E B F C A)
level_order = %w(A B C D E F)
build_tree(pre_order, in_order).show
build_tree_post_order(post_order, in_order).show
