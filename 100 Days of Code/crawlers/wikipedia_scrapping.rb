require 'rubygems'
require 'nokogiri'
require 'open-uri'
require 'open_uri_redirections'
WIKIPEDIA = "http://en.wikipedia.org/wiki/HTML"

page = Nokogiri::HTML(open(WIKIPEDIA, :allow_redirections => :safe))
infobox_h = page.css("table.infobox tr th")
infobox_h.each do |info|
  puts info.text
end
