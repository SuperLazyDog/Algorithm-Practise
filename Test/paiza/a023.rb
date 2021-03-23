# x x x x x x 0 x x x x x x
# x x x x x x x 0 x x x x x x

lines = readlines
count = lines[0].to_i
days = lines[1].split(' ')
coverages = Array.new(count, 0)
days.each.with_index do |d, i|
  if d == "0"
    s = (i -  6 < 0) ? 0 : i - 6
    e = (i + 6 < count) ? i + 6 : count -1
    for j in s..e do
      coverages[j] += 1
    end
  end
end

length = 0
tmp = 0
is_first = true
for i in 0...count do
  if coverages[i] < 2
    if is_first || length < tmp
      is_first = false
      length = tmp
    end
    tmp = 0
  else
    tmp += 1
  end
end
if length < tmp
  length = tmp
end
if length < 7
  length = 0
end
puts length
