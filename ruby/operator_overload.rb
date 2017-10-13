class MyAddition
    def initialize(me)
        @me = me
    end
    def +(rhs, *args, &blk)
        @me+rhs * 2
    end
    def /(rhs, *args, &blk)
        @me / rhs * 2
    end
end

p = MyAddition.new(43)
puts p+3
puts p/3