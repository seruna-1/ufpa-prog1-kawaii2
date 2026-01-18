#include "pokedex.hpp"

#include <cstring>

bool
Pokedex::parse_command_line_add_pokemon
(char *to_be_parsed)
{
	printf("Adding by parsing: %s\n", to_be_parsed);
	return true;
}

bool
Pokedex::parse_command_line
(
	int argc,
	char **argv
)
{
	if (argc <= 1)
	{ return false; }

	// Look for keys and delegate their values to specific functions
	for(int i = 1; i < argc; i++)
	{
		char *key = argv[i];

		if (strcmp(key, "--add") == 0)
		{
			return parse_command_line_add_pokemon(argv[++i]);
		}
		else
		{
			printf("Not ok.\n");
			return false;
		}
	}

	return true;
}