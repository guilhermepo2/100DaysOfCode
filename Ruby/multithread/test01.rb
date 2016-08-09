#!/usr/bin/ruby
# Creating Ruby Threads


def func1
  i = 0
  while i <= 2
    puts "func1 at #{Time.now}"
    sleep(8)
    i = i+1
  end
  
  puts "func1 ended at #{Time.now}"
end

def func2
  j = 0
  while j <= 2
    puts "func2 at #{Time.now}"
    sleep(4)
    j = j + 1
  end

  puts "func2 ended at #{Time.now}"
end

puts "Started at #{Time.now}"
t1 = Thread.new{func1()}
t2 = Thread.new{func2()}
t1.join
t2.join
puts "End at #{Time.now}"
