lines = readlines
power, point = lines[0].split(' ').map{ |i| i.to_i }

@max = power
def compute_power(power, point, min=1)
  if point > 0
    (min..point).each do |i|
      compute_power(power*(100+i)/100, point-i, min)
    end
  else
    if @max < power
      @max = power
    end
  end
end

compute_power(power, point)
puts @max
