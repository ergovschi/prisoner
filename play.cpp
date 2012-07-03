#include <string>
#include <iostream>
#include <functional>
#include "include/prisoner.h"

#define STOP cin.get(cr)

int main(){

    /*Bash is taking care of this */
    std::function<Prisoner*()> new_prisoner[] = 
    {
    };
    int num_players;

    /* End of Bash generated code */

    std::cout <<"*-----------------------------------*\n"
         <<"|                                   |\n"
         <<"|    PRISONER'S DILEMMA TOURNAMENT  |\n"
         <<"|                                   |\n"
         <<"*-----------------------------------*\n";


    char cr;


    int i;
    for (i = 0; i < num_players; i++)
    {
        Prisoner* s = new_prisoner[0]();
        std::cout << s->prisonerName;
    }

    STOP;

    return 0;
}
