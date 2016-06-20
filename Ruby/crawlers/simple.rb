require 'rubygems'
require 'nokogiri'
require 'open-uri'
require 'open_uri_redirections'
PAGE_URL = "http://ruby.bastardsbook.com/files/hello-webpage.html"

page = Nokogiri::HTML(open(PAGE_URL, :allow_redirections => :safe))
puts page.class      # => Should be Nokogiri::HTML::Document

puts "Scrapping webpage title"
puts page.css("title")[0].name # => component name
puts page.css("title")[0].text # => page title
puts

# The css method DOES NOT RETURN THE TEXT of the element. It returns an array, more specifically, a Nokogiri data object, with its own methods and elements, including text, name ...

# Extracting Links from the website
links = page.css("a")
puts "Scrapping webpage links"
puts links.length
puts links[0].text
puts links[0]["href"]
puts

# Extracting links with news class on the website
puts "Links with news category"
#news_links = page.css("a").select{|link| link['data-category'] == "news"}
news_links = page.css("a[data-category=news]")
news_links.each{|link| puts link['href'] }
puts

# Referring back to our sample HTML, write a selector that chooses only the anchor tags in the div that has the id of "references". Print out the text within the anchor tag followed by its URL.
puts "Exercise"
exercise = page.css("#references a")
exercise.each{|link| puts "#{link.text}\t#{link['href']}"}


