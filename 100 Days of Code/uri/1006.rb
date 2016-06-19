a = gets.chomp.to_f
b = gets.chomp.to_f
c = gets.chomp.to_f

MEDIA = "%.1f" % (((2.0*a)+(3.0*b)+(5*c))/10)
puts "MEDIA = #{MEDIA}"
