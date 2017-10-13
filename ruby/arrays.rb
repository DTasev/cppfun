a = [1,2,3,4,5]
a = ['test','banana','blue']

a << 'bonus'
puts a

puts "For each #1"
a.each do |item|
    puts item
end

puts "For each #2"
a.each {|item| puts item}