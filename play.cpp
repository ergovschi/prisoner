#include <string>
#include <iostream>
#include <functional>
#include "include/prisoner.h"
#include "prisoners/sergiu.h"

#define STOP cin.get(cr)

int main(){

    /*Bash is taking care of this */

    /* End of Bash generated code */
    std::function<Prisoner*()> new_prisoner[] = 
    {
        [](){return new Sergiu;},
    };

    char cr;
    std::cout <<"*-----------------------------------*\n"
         <<"|                                   |\n"
         <<"|    PRISONER'S DILEMMA TOURNAMENT  |\n"
         <<"|                                   |\n"
         <<"*-----------------------------------*\n";


    Prisoner* s = new_prisoner[0]();

    std::cout << s->prisonerName;

    STOP;

    return 0;
}
