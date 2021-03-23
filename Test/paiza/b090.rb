# TODO: 困了，下次再说 2021/3/23 23:36
# lines = readlines
# count, seats = lines.shift.split(' ').map{ |i| i.to_i }
# datas = lines.map { |n| n.to_i }
# tmp = []
# seats.times do |i|
#   tmp += datas.each_with_index.map { |d, j| {j => d/(i+1)} }
# end
# out = Array.new(count, 0)
# tmp.sort {|a, b|  b.values.first <=> a.values.first }.group_by { |h| h.values.first}.each do |ks, vs|
#   if ks.count == 1
#     out[ks] +=1
#   else
#
#   end
# end


# each do |h|
#   if out.sum == seats
#     puts out
#     break
#   end
#   h.each do |k, v|
#     out[k] += 1
#   end
# end
