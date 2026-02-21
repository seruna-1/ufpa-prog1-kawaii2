#include <cstdio>
#include <cstring>
#include <iostream>
#include "command_line/pokedex.hpp"
#include "menu/main.cpp"
// autores: Mateus Barreto, Yuri Delgado, Nicolas Alho
// Este programa é uma Pokedex simplificada. Ele registra pokemons e alguns de seus atributos(id, geração, fraquezas, resistencias, etc)
// conta com 7 funções: Load, add, search, print, remove, sort e save. A explicação de cada função reside em comentários na menu/main.cpp
int
main
(
    int argc,
    char **argv
)
{
    bool tui = true;
    tui = menu(argc);
    CommandLinePokedex command_line_pokedex;
    CommandLinePokedex::ParsingResult parsing_result = command_line_pokedex.parse(argc, argv);
    switch(parsing_result)
    {
        case CommandLinePokedex::ParsingResult::ERROR:
            if (tui)
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
