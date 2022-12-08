+#pragma once

#include "ENEMY.h"

class ANIMAL : public ENEMY
{

public:
    ANIMAL();
    ANIMAL(int x);
    int isWhat();
    void sound()    
};
