#include <string>
#include <iostream>
#include <functional>
#include "include/prisoner.h"

#define CLAIM 0 
#define SETTLE 1
#define STOP cin.get(cr)                 

int score[100];
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

    int num_rounds = 100;

    int i, j, round, move1, move2, aux,  ts1, ts2;

    pair<int, int> scoring[2][2];
    scoring[SETTLE][SETTLE] = make_pair(2,2);
    scoring[CLAIM][SETTLE] = make_pair(5,0);
    scoring[SETTLE][CLAIM] = make_pair(0,5);
    scoring[CLAIM][CLAIM] = make_pair(0,0);

    for (i = 0; i < num_players; i++) {
        Prisoner* s = new_prisoner[i]();
        std::cout << s->prisonerName <<' ';
    }
    STOP;

    for (i = 1; i < num_players; i++) 
        for (j = 0; j < i; j++)
        {
            ts1 = 0;
            ts2 = 0;
            Prisoner* p1 = new_prisoner[i]();
            Prisoner* p2 = new_prisoner[j]();
            
            std::cout << "ROUND: " << p1->prisonerName << " VS " << p2->prisonerName << '\n';

            move2 = num_rounds;
            move1 = num_rounds;

            for (round = 0; round < 100; round++) {
                aux = move1;
                move1 = p1->getMove(move2);
                move2 = p2->getMove(aux);

                ts1 += scoring[move1][move2].first;
                ts2 += scoring[move1][move2].second;
            }

            score[i]+=ts1;
            score[j]+=ts2;

            std::cout << "RESULTS: "
                << p1->prisonerName << " : " << ts1 << " | "
                << p2->prisonerName << " : " << ts2;
            STOP;
        }
    
    std::cout << '\n' << '\n'
        << "^*^*^*^*^^*^*^*^^*^*^*^*^^*^*^*^*^*^*^*^*^*^*^*^^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n"
        << "                                       FINAL SCORES                                      \n"
        << "#########################################################################################\n\n";

    for (i = 0; i < num_players; i++) {
        Prisoner* s = new_prisoner[i]();

        std::cout << s->prisonerName << ' ' << score[i] << '\n';
    }



    return 0;
}
