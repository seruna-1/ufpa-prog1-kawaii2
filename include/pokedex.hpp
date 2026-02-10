#include <string>
#include <memory>

#include "pokedex_pokemon_entry.hpp"
#include "pokemon.hpp"

class Pokedex
{
protected:
	std::unique_ptr<PokedexPokemonEntry> first_pokemon_entry;

public:
	enum class SortType
	{
		ID,
		EVOLTUION_STAGE,
		GENERATION,
		WEIGTH
	};

	int
	size
	(void);

	Pokemon
	get
	(int index);

	// Validates and inserts pokemon.
	bool
	add
	(Pokemon pokemon);

	bool
	remove
	(std::string name);

	void
	print_to_stdout
	(void);

	bool
	save_to_file
	(const char* filename);

	bool
	load_from_file
	(const char* filename);

	void
	sort
	(SortType type);
};