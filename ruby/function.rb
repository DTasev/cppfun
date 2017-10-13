def repeat_three_times(value)
    puts value
    puts value
    puts value
end

def default_repeat_three_times(value='default_value')
    repeat_three_times(value)
end

repeat_three_times(3)
default_repeat_three_times()