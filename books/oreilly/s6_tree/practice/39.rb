# -------------------------
# 6-39
# -------------------------
def get_height(ary)
  i = 0
  count = ary.count
  max_height = 0
  for i in 1...ary.count do
    cur = i
    height = 0
    while cur != -1
      cur = ary[cur]
      height += 1
    end
    if max_height < height
      max_height = height
    end
  end
  return max_height
end

ary = "01660027".split('').map(&:to_i)
ary.unshift -1
puts get_height(ary)
