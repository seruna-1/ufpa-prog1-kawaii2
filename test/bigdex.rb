require 'json'

json_url = 'https://raw.githubusercontent.com/olitreadwell/pokemon-classic-json/refs/heads/main/pokedex.json'
json_text = `curl -L #{json_url}`

json = JSON.parse(json_text)

# Convert to our syntax
json["pokemon"].each do |entry|
	puts "id: " + entry["num"] + ";"
	puts "name: " + entry["name"] + ";"
	puts "weight: " + entry["weight"].delete(" kg") + ";"
	puts "\n"
end
