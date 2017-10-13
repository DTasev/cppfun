class ClassName
    def initialize
        puts 'hi'
    end

    def area_of_a_circle(radius)
        3.14 * radius * radius
    end
end

a = ClassName.new
puts a.area_of_a_circle(10)
