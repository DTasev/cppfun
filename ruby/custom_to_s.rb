class Person
    def initialize(fn, ln)
        @fn=fn
        @ln=ln
    end
    def to_s()
        "#{@fn} #{@ln}"
    end
end

p = Person.new("Patrick", "Rothfuss")
puts p.to_s