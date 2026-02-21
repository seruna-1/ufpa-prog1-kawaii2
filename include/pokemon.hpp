#pragma once

#include <string>
#include <memory>

class Pokemon
{
public:
	unsigned int global_id; // ID in global pokedéx.
	std::string name;
	unsigned int base_stat_total; //sum of all of the pokemons attributes
	float weight; // in kg
	unsigned int generation; // generation that introduced this pokemon, from 1 to 10
	std::string abilities[5]; // we just assume 5 for now, since std::vector is prohibited
	std::string resistances[12]; //12 is the maximum number of resistances a pkmn can have
	std::string weaknesses[7];
	std::string egg_group[5];
	std::string immunities[5];

	void
	print
	(void);
};
