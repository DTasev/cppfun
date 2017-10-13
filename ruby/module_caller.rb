require_relative 'test_module/module'
class OtherCLass
  extend MyModule # This adds the methods from the module into CLASS methods
  include OtherModule # This adds the methods from the module into INSTANCE methods

  attr_reader :duhduh

  def initialize()
    # call class defined in the module
    @duhduh = MyModule::MyClass.new
  end
  def getd()
    @duhduh.test_function
  end
end

d = OtherCLass.new
puts d.getd
puts d.common
puts OtherCLass.common
