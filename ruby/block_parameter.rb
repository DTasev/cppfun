class Repeater
    def initialize(number_of)
        @number_of = times
    end
    def each(&block)
        @number_of.times {block.call}
    end
end
def n_times(number_of, &block)
    number_of.times { block.call }
end

r = Repeater.new(3)
value = 0
r.each { value += 1 }
puts value