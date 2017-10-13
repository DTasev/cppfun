def explain_product(a, b)
  "The result of #{a} * #{b} is #{a*b}"
end

def my_sexy_product_updater(product, *overwrite_fields)
  # update the fields of the product
  overwrite_fields.each do |attr|
    key, value = attr.first
    if product.has_key?(key) && !key.nil?
      product[key] = value
    end
    return product
  end
end

class Person
  def initialize(age)
    # using self.age here calls the custom setter to enforce the restrictions on age
    self.age = age
  end

  def age
    age
  end

  def age=(new_age)
    if new_age >= 0 && new_age <= 120
      @age=new_age
    else
      raise ArgumentError.new("Invalid age")
    end
  end
end
