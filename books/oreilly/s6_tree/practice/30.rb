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
# 6-30
# -------------------------
# 自己的方法
# def zigzag_traversal(node)
#   return if node.nil?
#   queue = [node, nil]
#   reverse = false
#   datas = []
#   while !queue.empty?
#     cur = queue.shift
#     if cur.nil?
#       if !queue.empty?
#         queue.push nil
#       end
#       if reverse
#         puts datas.reverse.join ", "
#       else
#         puts datas.join ", "
#       end
#       datas = []
#       reverse = !reverse
#     else
#       datas.push cur.data
#       queue.push cur.left if !cur.left.nil?
#       queue.push cur.right if !cur.right.nil?
#     end
#   end
# end
# 书上
def zigzag_traversal(node)
  return if node.nil?
  current_level = [node]
  next_level = []
  reverse = false
  while !current_level.empty?
    cur = current_level.pop
    print "#{cur.data} "
    if reverse
      next_level.push cur.right if !cur.right.nil?
      next_level.push cur.left if !cur.left.nil?
    else
      next_level.push cur.left if !cur.left.nil?
      next_level.push cur.right if !cur.right.nil?
    end
    if current_level.empty?
      current_level, next_level = next_level, current_level
      reverse = !reverse
      puts ""
    end
  end
end
zigzag_traversal(a)
