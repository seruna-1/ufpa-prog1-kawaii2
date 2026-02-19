#include <cstdio>

#include "graphical/pokedex.hpp"

int
main
(void)
{
	GraphicalPokedex graphical_pokedex;
	if (graphical_pokedex.run())
	{ return EXIT_SUCCESS; }
	else { return EXIT_FAILURE; }
}