d = {'egg' => 0.1, 'butter' => 0.333}

d.each {|tuple| puts tuple}
d.each {|k,v| print "key: ", k, " value: ", v}
puts

puts "Accessing via key:", d['egg']

sym = { red: 'red', green: 'green' }
sym.each do |k,v|
     puts "#{k} #{v}"
end

puts sym[:red]