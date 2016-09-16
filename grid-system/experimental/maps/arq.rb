input_file = ARGV[0]
output_file = ARGV[1]

finalarq = ""

File.readlines(input_file).each do |l|
  x = l.split
  string_total = ""
  
  x.each do |a|
    string_total = string_total + "'#{a}',"
  end

  finalarq = finalarq + "new List<char> { #{string_total[0..(string_total.length() - 2)]} },\n"
end

File.write(output_file, finalarq[0..(finalarq.length()-3)])
