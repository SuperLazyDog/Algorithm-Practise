lines = readlines

@height, @weight = lines.shift.split(' ').map(&:to_i)
map = lines.map do |row| # true: is_land
  row.chomp.split('').map do |field|
    field == "#"
  end
end

def show_map(map)
  puts "show map"
  map.each do |row|
    puts row.join('|')
  end
end

def get_year(map, year=0)
  new_map = []
  map.each { |line| new_map.push line.dup }
  # show_map(map)
  all_sea = true
  @height.times do |i|
    @weight.times do |j|
      if map[i][j]
        all_sea = false
        if i == 0 || i == @height -1 || j == 0 || j == @weight - 1
          new_map[i][j] = false
        else
          if i > 0
            new_map[i][j] &&= map[i-1][j]
          end
          if i < @height - 1
            new_map[i][j] &&= map[i+1][j]
          end
          if j > 0
            new_map[i][j] &&= map[i][j-1]
          end
          if j < @weight - 1
            new_map[i][j] &&= map[i][j+1]
          end
        end
      end
    end
  end
  # show_map(map)
  # show_map(new_map)
  if all_sea
    return year
  else
    get_year(new_map, year+1)
  end
end

puts get_year(map)
