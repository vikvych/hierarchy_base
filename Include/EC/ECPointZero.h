#ifndef HIERARCHY_EC_POINT_ZERO_H
#define HIERARCHY_EC_POINT_ZERO_H

#include "EC.h"

void ECPointZero(ECPointT *Point){
    if(Point == NULL){
        return;
    }

    BigNumberSetFromInt(Point->X, 0);
    BigNumberSetFromInt(Point->Y, 0);
}

#endif
