#include "../pokedex.hpp"

class CommandLinePokedex
{
protected:
	Pokedex pokedex;

public:
	enum class ParsingResult
	{
		ERROR, // Exit with error
		CONTINUE, // Ready to fetch data to pokedex
		GRACEFUL_EXIT // No errors, but premature stop, a.k.a help
	};

	static const char *help_message;

	ParsingResult
	parse
	(
		int argc,
		char **argv
	);
};