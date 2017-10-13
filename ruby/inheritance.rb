class Abc
    def a
        'a'
    end
    def b
        'b'
    end
    def c
        'c'
    end
end
class Abcd < Abc
    def d
        'd'
    end
end

b = Abcd.new
puts b.a
puts b.b
puts b.c
puts b.d