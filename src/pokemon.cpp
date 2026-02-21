#include "pokemon.hpp"
#include <iostream>

void
Pokemon::print
(void)
{
	std::cout << "id: " << global_id << ";" << std::endl;
	std::cout << "name: " << name << ";" << std::endl;
	std::cout << "base stat total: " << base_stat_total << ";" << std::endl;
	std::cout << "generation: " << generation << ";" << std::endl;
	std::cout << "weight: " << weight << ";" << std::endl;
	std::cout << "weaknesses: " << weaknesses[0] << ";" << std::endl;
	std::cout << "resistances: " << resistances[0] << ";" << std::endl;
	std::cout << "immunities: " << immunities[0] << ";" << std::endl;
	std::cout << "egg group: " << egg_group[0] << ";" << std::endl;
}
