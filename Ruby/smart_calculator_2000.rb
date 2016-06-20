$sum_phrases = ["This one is really easy, you know",
               "Ha! You are underestimating me!",
               "Easy...",
               "Please try a lit bit more...",
               "YOU UNDERESTIMATE MY POWER...",
               "The answer is 42! Ha. Just Kidding"
               ]
$minus_phrases = ["I don't like subtracting.",
                  "Maybe I should... Oh, I should compute.",
                  "ten raised to nine minus one plus seventeen is...",
                  "I'm hungry, I'll subtract a bite from this hamburguer! LOL",
                  "Maaaaaaaaan... This one is easy!"
                 ]
$multiply_phrases = ["So you are trying to complicate a little bit...",
                     "I don't guarantee that I will get it right...",
                     "Hmm, this one should be easy peasy",
                     "I have this amount of fish and this amount of chips... So... Oh, wait..",
                     "I have a dream that... Nevermind..."
                    ]
$division_phrases = ["Did I tell you that I was the worst calculator in division at my class?",
                     "One day a guy relied on me to divide his money between his son's! It was a funny day.",
                     "Can I divide by zero?",
                     "Maybe it's easier if I subtract and sum the numbers... no one will notice...",
                     "two divided by zero, Oh yes, Oh yes, not now mr. supermassive black hole",
                     "OH MAN I FEEL LIKE THIS ONE I WILL GET CORRECTLY"
                    ]

def compute(input)
  if(input == "exit")
    abort("See you!")
  end

  puts("Hmm... Let me think...")
  sleep 2
  operator_a = 0
  operator_b = 0
  total = 0

  operations = input.split("")
  operations.delete_if { |l| l == " " }

  operator_a = Integer(operations[0])
  operator_b = Integer(operations[2])
  case operations[1]
  when '+'
    puts($sum_phrases[rand($sum_phrases.count)])
    sleep 1.0
    total = operator_a + operator_b
  when '-'
    puts($minus_phrases[rand($minus_phrases.count)])
    sleep 1.0
    total = operator_a - operator_b
  when '*'
    puts($multiply_phrases[rand($multiply_phrases.count)])
    sleep 2
    total = (operator_a * operator_b) - rand(10)
  when '/'
    puts($division_phrases[rand($division_phrases.count)])
    sleep 3
    if(operator_b == 0)
      puts "Ha. Something funky happened..."
    else
      total = (operator_a + 1 / operator_b) * rand(5)
    end
  else
    puts "Sorry! I don't know how to do that..."
  end

  puts("Hmm.... I think I got it!")
  sleep 0.5
  puts("YOUR RESULT IS: #{total}!")
  sleep 0.5
  
end

def main()
  puts "I'm the best calculator around. Please enter any kind of calculation you want."
  while(true)
    print "> "
    input = gets.chomp
    compute(input)
  end
  puts
end

main()
