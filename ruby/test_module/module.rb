module OtherModule
  def common
    "Common function in OtherModule"
  end
end
module MyModule
  # this doesn't make any sense, it is an instance function for a module, that cannot e instantiated
  def common
    "Common function in MyModule"
  end

  def self.self_function
    "An actually callable function"
  end

  class MyClass
    def test_function()
      "Test function of MyClass"
    end
  end
end

