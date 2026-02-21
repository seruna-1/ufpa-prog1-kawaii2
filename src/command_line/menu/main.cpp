#include <iostream>
#define MENU_OPTION_1 "load"
#define MENU_OPTION_2 "add"
#define MENU_OPTION_3 "search"
#define MENU_OPTION_4 "print"
#define MENU_OPTION_5 "remove"
#define MENU_OPTION_6 "sort"
#define MENU_OPTION_7 "save" 
int
userinput //handles user input, converts string user input into a valid integer for operation selection and returns that value
(void)
{
    int option = 0;
    std::string option_string;
    bool display_error_message = false;
    
    while (!(option >= 1 && option <= 7))
    {
        if (display_error_message)
            printf("Error: Invalid User Input. Please try again.\n");
        
        if (std::cin >> option)
        {
            if (option >= 1 && option <= 7)
                return option;
        }
        else std::cin.clear(); 
        
        if(std::cin >> option_string)
        {
                if (option_string == MENU_OPTION_1)
                    option = 1;
                else if (option_string == MENU_OPTION_2)
                    option = 2;
                else if (option_string == MENU_OPTION_3)
                    option = 3;
                else if (option_string == MENU_OPTION_4)
                    option = 4;
                else if (option_string == MENU_OPTION_5)
                    option = 5;
                else if (option_string == MENU_OPTION_6)
                    option = 6;
                else if (option_string == MENU_OPTION_7)
                    option = 7;
        }
        display_error_message = true;
    }
    return option;       
}
void printmenu(void){
std::cout <<"___________________________________________________________________________________________\n";                            
std::cout <<"||        ████████████                                                                   ||\n";
std::cout <<"||     ██████████████████                                                                ||\n";
std::cout <<"||   ██████████████████████                                                              ||\n";
std::cout <<"||  ████████████████████████  _______         __                   __                    ||\n";
std::cout <<"||  ██████████    ██████████ |_   __ \\       [  |  _              |  ]                   ||\n";
std::cout <<"|| █████████        █████████  | |__) | .--.  | | / ] .---.   .--.| | .---.  _   __      ||\n"; 
std::cout <<"|| █████████        █████████  |  ___// .'`\\ \\| '' < / /__\\\\/ /'`\\' |/ /__\\\\[ \\ [  ]     ||\n";
std::cout <<"|| ██      ██      ██      ██ _| |_   | \\__. || |`\\ \\| \\__.,| \\__/  || \\__., > '  <      ||\n";
std::cout <<"||  ██      ████████      ██ |_____|   '.__.'[__|  \\_]'.__.' '.__.;__]'.__.'[__]`\\_]     ||\n";
std::cout <<"||   ██                  ██                                                              ||\n";
std::cout <<"||    ██                ██  by: Mateus Cezario, Yuri Delgado and Nicolas Alho.           ||\n";
std::cout <<"||      ███          ███                                                                 ||\n";
std::cout <<"||         ██████████                                                                    ||\n";
std::cout <<"||                                                                                       ||\n";
std::cout <<"||                    tip: input can either be numbers or the the first word of          ||\n";
std::cout <<"||                      the operation, all lowercase. (1 or load, 2 or add, etc)         ||\n";
std::cout <<"||                                 Select desired operation:                             ||\n";
std::cout <<"||                                                                                       ||\n";
std::cout <<"||                    1. Load file              5. Remove Pokemon                        ||\n";
std::cout <<"||                    2. Add Pokemon            6. Sort Pokemon                          ||\n";
std::cout <<"||                    3. Search Pokemon         7. Save and Exit                         ||\n";
std::cout <<"||                    4. Print Pokemon                                                   ||\n";
std::cout <<"||_______________________________________________________________________________________||\n";
}
bool menu(int& argc){
    if (argc <= 1)
    {
        Pokedex pokedex;
        bool running = true;

        std::cout << "GUI mode: Text-based \n";
        printmenu();
        while (running)
        {
            
            switch (userinput()) //has no default because userinput() already handles errors and always returns a valid operation number;
            {
                case 1:
                {
                    std::string filename;
                    std::cout << "Type the file name: ";
                    std::cin >> filename;
                    if (pokedex.load_from_file(filename.c_str()))
                    { system("clear"); printmenu();  std::cout << "File loaded successfully\n"; }
                    break;
                }
                

		case 2:
		{
		    Pokemon p;
	
		    int current_size = pokedex.get_size();
		    if (current_size == 0)
		    { p.global_id = 1; }
		    else
		    { p.global_id = pokedex.at(current_size - 1).global_id + 1; }
			
		    std::cout << "ID: " << p.global_id << "\n";
			
		    std::cout << "Name: ";
		    std::cin >> std::ws;
		    std::getline(std::cin, p.name);
			
		    std::cout << "Base stat total: ";
		    std::cin >> p.base_stat_total;
			
		    std::cout << "Weight: ";
		    std::cin >> p.weight;
			
		    std::cout << "Generation: ";
		    std::cin >> p.generation;
			
		    std::cout << "Abilities: ";
		    std::cin >> std::ws;
		    std::getline(std::cin, p.abilities[0]);
			
		    std::cout << "Weaknesses: ";
		    std::cin >> std::ws;
		    std::getline(std::cin, p.weaknesses[0]);
			
		    std::cout << "Resistances: ";
		    std::cin >> std::ws;
		    std::getline(std::cin, p.resistances[0]);
			
		    std::cout << "Immunities: ";
		    std::cin >> std::ws;
		    std::getline(std::cin, p.immunities[0]);
			
		    std::cout << "Egg group: ";
	            std::cin >> std::ws;
		    std::getline(std::cin, p.egg_group[0]);
		
		    if (pokedex.add(p))
		    { std::cout << "Pokemon added to the end of the Pokedex.\n"; }
		    break;
		    }

		case 3:
                {
                    std::cout << "Search by:\n1. Name\n2. ID\nChoose: ";
                    int search_opt;
                    std::cin >> search_opt;
                    if (search_opt == 1)
                    {
                        std::string name;
                        std::cout << "Type the name: ";
                        std::cin >> name;
                        Pokemon p = pokedex.get(name);
                        if (p.name != "") 
			{ system("clear"); printmenu(); p.print(); }
                        else 
			{ system("clear"); printmenu(); std::cout << "Pokemon not found.\n"; }
                    }
                    else if (search_opt == 2)
                    {
                        unsigned int id;
                        std::cout << "Type the ID: ";
                        std::cin >> id;
                        Pokemon p = pokedex.get_by_id(id);
                        if (p.name != "") { system("clear"); printmenu(); p.print(); }
                        else { system("clear"); printmenu(); std::cout << "Pokemon not found.\n"; }
                    }
                    break;
                }
                case 4:
                {
                    std::cout << "1. Print All\n2. Print Interval\nChoose: ";
                    int print_opt;
                    std::cin >> print_opt;
                    if (print_opt == 1)
                    { pokedex.print(); printmenu();}
                    else if (print_opt == 2)
                    {
                        int start, end;
                        std::cout << "First position: ";
                        std::cin >> start;
                        std::cout << "Last position: ";
                        std::cin >> end;
                        pokedex.print_range(start, end);
                        printmenu();
                    }
                    break;
                }
                case 5:
                {
                    std::string name;
                    std::cout << "Type the name to remove: ";
                    std::cin >> name;
                    if (pokedex.remove(name))
                    {system("clear"); printmenu(); std::cout << "Pokemon successfully removed.\n"; }
                    else
                    { system("clear"); printmenu(); std::cout << "Pokemon not found.\n"; }
                    break;
                }
                case 6:
                {
                    int sorttype;
                    std::cout << "Select the desired sorting parameter: \n 1 for id\n 2 for weight\n";
                    std::cin >> sorttype;
                    if (sorttype == 1)
                    { pokedex.sort(Pokedex::SortType::ID); system("clear"); printmenu(); std::cout<<"Sorting by id was successful.\n"; }
                    else if (sorttype == 2)
                    { pokedex.sort(Pokedex::SortType::WEIGHT); system("clear"); printmenu(); std::cout<<"Sorting by weight was successful.\n"; }
                    else
                        std::cout<<"Invalid sorting parameter.\n";
                    break;
                }
                case 7:
                {
                    std::string filename;
                    std::cout << "File name to save the changes: ";
                    std::cin >> filename;
                    if (pokedex.save_to_file(filename.c_str()))
                    {
                        std::cout << "Data successfully recorded. Exiting..\n";
                        running = false;
                    }
                    break;
                }
            }
        }
    }
    return false;
}
