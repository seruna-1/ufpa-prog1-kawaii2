#include <cstdio>
#include <cstring>

#include "command_line/pokedex.hpp"

int
main
(
	int argc,
	char **argv
)
{
	CommandLinePokedex command_line_pokedex;
	CommandLinePokedex::ParsingResult parsing_result = command_line_pokedex.parse(argc, argv);
	switch(parsing_result)
	{
		case CommandLinePokedex::ParsingResult::ERROR:
			fprintf(stderr, "Error parsing commandline. Pass --help for usage.\n");
			return EXIT_FAILURE;
			break;
		case CommandLinePokedex::ParsingResult::GRACEFUL_EXIT:
			return EXIT_SUCCESS;
			break;
		case CommandLinePokedex::ParsingResult::CONTINUE:
			return EXIT_SUCCESS;
			break;
	}
	return EXIT_FAILURE;
}