require 'rubygems'
require 'nokogiri'
require 'open-uri'
require 'open_uri_redirections'

# BASE LINK and github user
GITHUB_BASE_LINK = "http://github.com"
GITHUB_REPOSITORIES = "?tab=repositories"
GITHUB_USER = "guilhermepo2"

# Where to save the github information from the user
# Not Currently in use
# DATA_DIR = "github-scrapping/"
# Dir.mkdir(DATA_DIR) unless File.exists?(DATA_DIR)

# Start Scrapping
page_to_scrap = "#{GITHUB_BASE_LINK}/#{GITHUB_USER}"
page = Nokogiri::HTML(open(page_to_scrap, :allow_redirections => :safe))

# Getting profile info on github
info = page.css("div.one-fourth")

# Getting da names
names = info.css("h1.vcard-names div")
names.each do |n|
  print n.attribute("itemprop").text + ": " +
        n.text + "\n"
end

# Some infos about location, email, link and data
infos = info.css("li.vcard-detail")
infos.each do |i|
  print i.attribute("aria-label").text + ": " + i.text + "\n"
end

more_info = info.css("a.vcard-stat")
more_info.each do |t|
  print t.css("strong.vcard-stat-count").text +
        " " + t.css("span.text-muted").text + "\n"
end

# repositories on the main page info
repo_info = page.css("div.overview-tab > div")
puts("-----------------------------------------------------------------")
puts repo_info.css("div.single-column h3").text.strip
box = repo_info.css("div.single-column ul li")

box.each do |b|
  puts b.css("a")[0]["href"]
  puts b.css("span.repo").text.strip.delete("\n")
  puts b.css("span.repo-description").text.strip.delete("\n")
  puts
end
puts("-----------------------------------------------------------------")

# Contributions last year
puts("-----------------------------------------------------------------")
puts repo_info[1].css("h3").text
puts("-----------------------------------------------------------------")

# Contribution activity
puts("-----------------------------------------------------------------")
puts repo_info[2].css("h2").text
puts repo_info[2].css("h3").text.strip.delete("\n")
contrib_list = repo_info[2].css("ul li")

contrib_list.each do |cl|
  puts "#{GITHUB_BASE_LINK}"+cl.css("a").attribute("href")
  puts cl.text.strip
  puts
end
puts("-----------------------------------------------------------------")


# -----------------------------------------------------------------------
# -----------------------------------------------------------------------
# ------------------ GETTING ALL REPOSITORIES INFORMATION ---------------
# -----------------------------------------------------------------------
# -----------------------------------------------------------------------

repos_page_link = "#{GITHUB_BASE_LINK}/#{GITHUB_USER}#{GITHUB_REPOSITORIES}"
repos_page = Nokogiri::HTML(open(repos_page_link, :allow_redirections => :safe))
repos = repos_page.css("ul.repo-list > div")

repos.each do |r|
  puts 
  puts "Repository: " + r.css("h3").text.strip.delete("\n")
  puts "Description: " + r.css("p.repo-list-description").text.strip.delete("\n")
  puts "Update: " + r.css("p.repo-list-meta").text.strip.delete("\n")
  puts 
  m_info = r.css("div.repo-list-stats")
  puts "Programming Language: " + m_info.css("span").text.strip.delete("\n") unless m_info.css("span").text.strip.delete("\n").empty?
  puts "Stars: " + m_info.css("a")[0].text.strip.delete("\n")
  puts "Forks: " + m_info.css("a")[1].text.strip.delete("\n")
  puts
  puts("-----------------------------------------------------------------")
end

