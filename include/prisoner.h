#ifndef __PRISONER_H
#define __PRISONER_H

#include <string>
using namespace std;

class Prisoner
{
    public:
        string prisonerName;
        virtual int getMove(int lastMove) = 0;
};
#endif
