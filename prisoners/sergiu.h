#include <string>
#include "../include/prisoner.h"

#define CLAIM 0
#define SETTLE 1

#define MAX_NUM_GAMES 100

using namespace std;

class Sergiu : public Prisoner
{
    public:
        Sergiu();
        int getMove(int lastMove);

    protected:
        int round;
        int numRounds;
        int opponent[MAX_NUM_GAMES];
        /* stuff to use for yourself */
};

Sergiu::Sergiu()
{
    round = 0;
    prisonerName = "Sergiu";
}

int Sergiu::getMove(int lastMove)
{
    if (round == 0) /* First round of the game, lastMove contains the total number */
    {               /* of rounds (4, 10 or 100)                                    */
        numRounds = lastMove;

        return SETTLE;
    } else {
        opponent[round] = lastMove;
        return SETTLE;
    }
    round += 1;
}
