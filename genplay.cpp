#include <iostream>
#include "include/prisoner.h"
#include "prisoners/sergiu.h"

using namespace std;

typedef Prisoner* (*CreateFunction)();

int main(){
    char cr;
    cout <<"*-----------------------------------*\n"
         <<"|                                   |\n"
         <<"|    PRISONER'S DILEMMA TOURNAMENT  |\n"
         <<"|                                   |\n"
         <<"*-----------------------------------*\n";

    CreateFunction prisoners[1] = {NULL};
    prisoners[0] = &Sergiu::Create;

    Prisoner* s = prisoners[0]();
    cout << s->prisonerName;
    cin.get(cr);
    
    return 0;
}
