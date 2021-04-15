require 'net/http'
require 'uri'
require "json"

class Recursive
  attr_accessor :seed, :n
  URL = "http://challenge-server.code-check.io/api/recursive/ask"

  def initialize(seed, n)
    @seed = seed
    @n = n
    @tmp_result = Array.new(51) # n: [1, 50], index: [0, 50]
  end

  def run
    recursive(@n)
  end

  private
  def askServer(n)
    uri = URI(URL)
    params = { seed: @seed, n: n }
    uri.query = URI.encode_www_form(params)
    res = Net::HTTP.get_response(uri)
    if res.is_a?(Net::HTTPSuccess)
      return JSON.parse(res.body, symbolize_names: true)[:result]
    else
      raise RuntimeError.new("htpp request failed")
    end
  end

  def recursive(n)
    return 1 if n == 0
    return 2 if n == 2
    if n % 2 == 0
      return recursive(n-1)+recursive(n-2)+recursive(n-3)+recursive(n-4)
    else
      @tmp_result[n] = askServer(n) if @tmp_result[n].nil?
      return @tmp_result[n]
    end
  end
end


def main(argv)
  if argv.count != 2
    str = "need 2 arguments"
    puts str
    raise RuntimeError.new(str)
  elsif !(argv[1] =~ /^[0-9]+$/)
    str = "the second argument must be integer"
    puts str
    raise RuntimeError.new(str)
  end
  seed = argv[0]
  n = argv[1].to_i
  puts "#{Recursive.new(seed, n).run}"
end

main(ARGV)
