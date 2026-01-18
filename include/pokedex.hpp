#include <string>
#include <list>

#include "pokemon.hpp"

class Pokedex
{
private:
	// --add <pokemon>
	bool
	parse_command_line_add_pokemon
	(char *to_be_parsed);

protected:
	std::list<Pokemon> pokemons;

public:
	enum class SortType
	{
		ID,
		EVOLTUION_STAGE,
		GENERATION,
		WEIGTH
	};

	bool
	parse_command_line
	(
		int argc,
		char **argv
	);

	// Validates and inserts pokemon.
	bool
	add_pokemon
	(Pokemon pokemon);

	bool
	delete_pokemon_by_global_id
	(unsigned int id);

	bool
	save_to_file
	(std::string filename);

	bool
	load_from_file
	(std::string filename);

	void
	sort
	(SortType type);
};