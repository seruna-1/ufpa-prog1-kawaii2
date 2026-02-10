#include <cstring>
#include <cstdio>
#include <iostream>
#include "command_line/pokedex.hpp"

const char *CommandLinePokedex::help_message =
"Non-interactive mode for pokedex."
"It performs operations on the source file, like adding or removing entries, only by command line flags.\n\n"
"Adding an entry to pokedex. OBS: See representation syntax.\n"
"\t--add <pokemon representation>\n"
"Deleting a pokemon by its name.\n"
"\t--remove <pokemon name>\n"
"Specifying the source file for entries:\n"
"\t--source <file>\n";

CommandLinePokedex::ParsingResult
CommandLinePokedex::parse
(
	int argc,
	char **argv
)
{
	if (argc <= 1)
	{
		return ParsingResult::ERROR;
	}

	// Look for keys and delegate their values to specific functions
	for(int i = 1; i < argc; i++)
	{
		char *key = argv[i]; // value = argv[++i]
		// Help
		if (strcmp(key, "--help") == 0)
		{
			printf("%s", help_message);
			return ParsingResult::GRACEFUL_EXIT;
		}
		// --add <pokemon>
		else if (strcmp(key, "--add") == 0)
		{
			printf("Adding by parsing: %s\n.", argv[i++]);
			//pokedex.add(argv[i++]);
			Pokemon test;
			test.name = "antedegemon";
			pokedex.add(test);
		}
		// --remove <pokemon>
		else if (strcmp(key, "--remove") == 0)
		{
			if (pokedex.remove(argv[i++]))
			{ printf("Removing %s from pokedex.\n.", argv[i++]); }
			else { printf("Pokemon %s not found.\n", argv[i++]); }
		}
		// Source file
		// --source <file>
		else if (strcmp(key, "--source") == 0)
		{
			pokedex.load_from_file(argv[++i]);
		}
	}
	pokedex.print_to_stdout();
	return ParsingResult::CONTINUE;
}