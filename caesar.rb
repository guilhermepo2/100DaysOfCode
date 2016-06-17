def encrypt_caesar_cipher(plaintext, key)
  cyphertext = ""
  (plaintext).split("").each do |letter|
    ascii = letter.ord
    if(ascii != 32)
      ascii = (((ascii+key) % 27) + 65)
    end
    cyphertext = cyphertext + ascii.chr
  end
  return(cyphertext)
end

def decrypt_caesar_cipher(cyphertext, key)
  plaintext = ""
  (cyphertext).split("").each do |letter|
    ascii = letter.ord
    if(ascii != 32)
      ascii = (((ascii - key) % 27) + 97)
    end
    plaintext = plaintext + ascii.chr
  end
  return(plaintext)
end

puts(encrypt_caesar_cipher("send more money", 20))
puts(decrypt_caesar_cipher(encrypt_caesar_cipher("send more money", 20), 20))

