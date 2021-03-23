lines = readlines
@d, @count = lines.shift.split(' ').map { |i| i.to_i }
@steps = lines.map { |l| l.to_i }

@path = []
def get_path(steps, path=[], i=0, cur=0)
  # puts "steps: #{steps}, cur: #{cur}, path: #{path.to_s}, i: #{i}, steps[i]: #{steps[i]}"
  if i >= steps.count
    if cur <= @d && cur >= -@d
      # puts path.join("")
      @path.push path
      return
    else
      return
    end
  end
  if cur > @d || cur < -@d
    return
  end
  get_path(steps, path+["L"], i+1, cur-steps[i])
  get_path(steps, path+["R"], i+1, cur+steps[i])
end
get_path(@steps)
puts @path.sort.first.join("")

#
# def get_path(steps)
#   stack = []
#   queue = steps.dup
#   path = []
#   cur = 0
#   while cur >= -@d && queue.empty?
#     while cur > -@d && !queue.empty?
#       step = queue.shift
#       cur -= step
#       stack.push step
#       path.push "L"
#     end
#     if cur >= -@d && queue.empty?
#       puts path.join('')
#       break
#     end
#     step = stack.pop
#     path.pop
#     cur += step*2
#     path.push "R"
#   end
#   puts path.join('')
# end
#
# get_path(@steps)
