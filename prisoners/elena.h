#include <string>
#include "../include/prisoner.h"

#define CLAIM 0
#define SETTLE 1

#define MAX_NUM_GAMES 100

using namespace std;

class Elena : public Prisoner
{
    public:
        Elena();
        int getMove(int lastMove);

    protected:
        int round;
        int numRounds;
        int opponent[MAX_NUM_GAMES];
        /* stuff to use for yourself */
};

Elena::Elena()
{
    round = 0;
    prisonerName = "Elena";
}

int Elena::getMove(int lastMove)
{
    if (round == 0) /* First round of the game, lastMove contains the total number */
    {               /* of rounds (4, 10 or 100)                                    */
        numRounds = lastMove;

        return CLAIM;
    } else {
        opponent[round] = lastMove;
        return CLAIM;
    }
    round += 1;
}
