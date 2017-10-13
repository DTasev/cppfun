require_relative 'test_module/test_module'
class OtherCLass
  def initialize()
    @duhduh = MyClass.new
  end
  def getd()
    @duhduh.test_function
    d = ->(param) {puts param}
    d(3)
  end
end

d = OtherCLass.new
d.getd
