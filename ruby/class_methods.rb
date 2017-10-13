class Class
    # instance method
    def pi
        3.14
    end
    # class method
    def self.wrong_pi
        4.24
    end
end

puts Class.wrong_pi
c = Class.new
puts c.pi

# list instance methods
puts Class.instance_methods

puts 'Hide the system ones, and just show user defined ones'
puts Class.instance_methods(false)