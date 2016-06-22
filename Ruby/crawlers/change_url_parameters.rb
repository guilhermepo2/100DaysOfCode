# Changing URL parameters
# seems to not be working

require 'rubygems'
require 'nokogiri'
require 'open-uri'
require 'open_uri_redirections'
require 'fileutils'

BASE_URL = 'http://explore.data.gov'
BASE_DIR = '/catalog/raw/?page='
LOCAL_DIR = 'data-hold/datagov-pages'

FileUtils.makedirs(LOCAL_DIR) unless File.exists?LOCAL_DIR

# the infos are on pages BASE_URL + BASE_DIR + 1,2,3,4,5...
# first page
page = Nokogiri::HTML(open(BASE_URL+BASE_DIR+'1', :allow_redirections => :safe))

# write HTML for page 1 on disk
File.open("#{LOCAL_DIR}/1.html", "w"){|f| f.write(page.to_html)}

# getting last page number
# last_page_number = page.css("a.end.lastLink.button")[0]['href'].match(/page=(\d+)/)[1].to_i # ?
last_page_number = 25

puts "Iterating from 2 to #{last_page_number}"

for pg_number in 2..last_page_number do
  puts "Getting #{pg_number}"
  File.open("#{LOCAL_DIR}/#{pg_number}.html", "w") do |f|
    f.write( open("#{BASE_URL}#{BASE_DIR}#{pg_number}").read )
  end
end
