#ifndef __PRISONER_H
#define __PRISONER_H

#include <string>
using namespace std;

class Prisoner
{
    public:
        string prisonerName;
        int getMove();
};

template<typename T>
class Creatable
{
    public:
        static Prisoner* Create()
        {
            return new T;
        }
};

#endif
