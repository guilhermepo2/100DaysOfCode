numero = Integer(gets.chomp)
horas = Integer(gets.chomp)
valor = gets.chomp.to_f
salario = "%.2f" % (horas*valor)

puts "NUMBER = #{numero}"
puts "SALARY = U$ #{salario}"
