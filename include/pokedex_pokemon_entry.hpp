#include <memory>
#include "pokemon.hpp"

class PokedexPokemonEntry
{
public:
	std::unique_ptr<PokedexPokemonEntry> predecessor;
	std::unique_ptr<PokedexPokemonEntry> successor;
	Pokemon pokemon;
};