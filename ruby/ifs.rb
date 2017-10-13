a = 10

if a == 10
    puts "a == 10!"
end

# what is the point of this shorthand if, without support for else???
puts "a is 9" if a == 9

# proper shorthand if
puts a==9 ? "a is 9" : "a is 10" 

if a == 9
    puts "a == 9!"
else
    puts "a == 10!"
end

if a == 9
    puts "a == 9!"
elsif
    puts "a == 10!"
end
