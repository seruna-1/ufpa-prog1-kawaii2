#include <cstdio>

#include "pokedex.hpp"

int
main
(
	int argc,
	char **argv
)
{
	Pokedex pokedex;

	if (!pokedex.parse_command_line(argc, argv))
	{
		fprintf(stderr, "Error parsing commandline.\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}