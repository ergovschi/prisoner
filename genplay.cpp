#include <iostream>
#include "include/prisoner.h"
#include "prisoners/sergiu.h"

using namespace std;

int main(){
    char cr;
    cout <<"*-----------------------------------*\n"
         <<"|                                   |\n"
         <<"|    PRISONER'S DILEMMA TOURNAMENT  |\n"
         <<"|                                   |\n"
         <<"*-----------------------------------*\n";

    Prisoner &s = Sergiu();
    cout << s.prisonerName;
    cin.get(cr);
    
    return 0;
}
