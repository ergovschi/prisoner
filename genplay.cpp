#include <iostream>
#include <string>
#include <iostream>
#include "include/prisoner.h"

#define STOP cin.get(cr)

using namespace std;

typedef Prisoner* (*CreateFunction)();

int main(){

    /*Bash is taking care of this */

    /* End of Bash generated code */
    function<Prisoner*()> new_prisoner[] = 
    {
        [](){return new Sergiu;},
    };

    char cr;
    cout <<"*-----------------------------------*\n"
         <<"|                                   |\n"
         <<"|    PRISONER'S DILEMMA TOURNAMENT  |\n"
         <<"|                                   |\n"
         <<"*-----------------------------------*\n";


    Prisoner* s = new_prisoner[0]();

    cout << s->prisonerName;

    STOP;

    return 0;
}
