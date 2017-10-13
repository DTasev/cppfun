5.times { |i| puts i }

# can also be written as
5.times do |i|
    puts i
end

5.times {|i| puts i.to_s + ' example'}

5.upto(10) { |i| print i, " " }