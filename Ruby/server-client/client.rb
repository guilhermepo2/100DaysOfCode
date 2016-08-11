require 'socket'

tcp_ip = '127.0.0.1'
tcp_port = 5005
s = TCPSocket.open(tcp_ip, tcp_port)

while line = s.gets
  puts line.chop
end

s.close
