#ifndef VEHICLE_H
#define VEHICLE_H

#include "ENEMY.h"

class VEHICLE : public ENEMY
{
    public:
        VEHICLER();
        VEHICLE(int x);
        int isWhat();
        void sound();
    
};

#endif