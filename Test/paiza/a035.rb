lines = readlines
@count = lines.shift.to_i
@datas = lines.map { |line| line.to_i }

@scores = []
def push_scores(i=0, score=0)
  if i < @count
    push_scores(i+1, score+@datas[i])
    push_scores(i+1, score)
  else
    @scores.push score if !@scores.include? score
  end
end
push_scores
puts @scores.count
@scores.sort.each { |s| puts s }
