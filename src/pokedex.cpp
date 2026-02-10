#include "pokedex.hpp"

#include <fstream>
#include <iostream>

int
Pokedex::size
(void)
{
	int size = 0;
	PokedexPokemonEntry *current_entry = first_pokemon_entry.get();
	while (current_entry != NULL)
	{
		current_entry = current_entry->successor.get();
		size++;
	}
	return size;
}

Pokemon
Pokedex::get
(int index)
{
	return first_pokemon_entry->pokemon;
}

bool
Pokedex::add
(Pokemon pokemon)
{
	PokedexPokemonEntry *current_entry = first_pokemon_entry.get();
	if (current_entry == NULL) {
		first_pokemon_entry = std::make_unique<PokedexPokemonEntry>();
		first_pokemon_entry->predecessor = NULL;
		first_pokemon_entry->successor = NULL;
		first_pokemon_entry->pokemon = pokemon;
		return true;
	}
	else
	{
		while (current_entry->successor != NULL)
		{ current_entry = current_entry->successor.get(); }
		current_entry->successor = std::make_unique<PokedexPokemonEntry>();
		current_entry->successor->pokemon = pokemon;
		return true;
	}
}

bool
Pokedex::remove
(std::string name)
{
	(void)name;
	return false;
}

void
Pokedex::print_to_stdout
(void)
{
	PokedexPokemonEntry *current_entry = first_pokemon_entry.get();
	while (current_entry != NULL)
	{
		std::cout << current_entry->pokemon.name;
		current_entry = current_entry->successor.get();
	}
}

bool
Pokedex::save_to_file
(const char* filename)
{
	std::ofstream output_file(filename);
	if (!output_file.is_open())
	{
		fputs("Error saving to file. File not open.", stderr);
		return false;
	}
	PokedexPokemonEntry *current_entry = first_pokemon_entry.get();
	while (current_entry != NULL)
	{
		output_file << current_entry->pokemon.name;
		current_entry = current_entry->successor.get();
	}
	output_file.close();
	return true;
}

bool
Pokedex::load_from_file
(const char* filename)
{
	std::ifstream source_file(filename);
	if (!source_file.is_open())
	{
		fputs("Error loading from file. File not open.", stderr);
		return false;
	}
	Pokemon pokemon;
	std::string line;
	while (std::getline(source_file, line))
	{
		size_t key_value_separator_position = line.find(":");
		if (key_value_separator_position == std::string::npos)
		{
			add(pokemon);
			//pokemon.clear();
		}
		else
		{
			std::string key = line.substr(0, key_value_separator_position);
			std::string value = line.substr( line.find_first_not_of(" ", key_value_separator_position+1) );
			if (key == "name")
			{ pokemon.name = value; }
			else
			{ fprintf(stderr, "Unsupported key: %s.\n", key.c_str()); }
		}
	}
	add(pokemon); // flush
	source_file.close();
	return true;
}

void
Pokedex::sort
(Pokedex::SortType type)
{
	(void)type;
	return;
}