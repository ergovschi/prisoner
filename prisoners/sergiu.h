#include <string>
#include "../include/prisoner.h"

#define FIRST_GAME 0
#define CLAIM 1
#define SETTLE 2

#define NUM_GAMES 100

using namespace std;

class Sergiu : public Prisoner,
               public Creatable<Sergiu>
{
    public:
        Sergiu();
        int getMove(int lastMove);

    protected:
        int turn;
        int opponent[NUM_GAMES];
        /* stuff to use for yourself */
};

Sergiu::Sergiu()
{
    turn = 0;
    prisonerName = "Sergiu";
}

int Sergiu::getMove(int lastMove)
{
    turn += 1;
    if (lastMove == FIRST_GAME)
    {
        /* This is the first move of the game */
        return CLAIM;
    } else {
        opponent[turn] = lastMove;

        /* Strategy stuff */
        return SETTLE;
    }
}
