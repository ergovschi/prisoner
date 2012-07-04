#include <string>
#include "../include/prisoner.h"
#include <iostream>

#define CLAIM 0
#define SETTLE 1

#define MAX_NUM_GAMES 100

using namespace std;

class Best : public Prisoner
{
    public:
        Best();
        int getMove(int lastMove);

    protected:
        int round;
        int numRounds;
        int opponent[MAX_NUM_GAMES];
        /* stuff to use for yourself */
};

Best::Best()
{
    round = 0;
    prisonerName = "Best";
}

int Best::getMove(int lastMove)
{
    round += 1;
    int move;
    if (round == 1) {
        numRounds = lastMove;
        opponent[0] = SETTLE;
    }
    else
        opponent[round - 1] = lastMove;
    
    return opponent[round -1];
}
