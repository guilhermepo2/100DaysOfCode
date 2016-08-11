require 'socket'

tcp_ip = '127.0.0.1'
tcp_port = 5005

server = TCPServer.open(tcp_port)
puts "Listening on port #{tcp_port}"

loop {
  client = server.accept                                # If someone connects...
  client.puts("Hey matey! its #{tcp_ip}:#{tcp_port}!")  # send this
  client.puts("Unfortunately we're closed now! k bye")
  client.close                                          # and disconnect
}
