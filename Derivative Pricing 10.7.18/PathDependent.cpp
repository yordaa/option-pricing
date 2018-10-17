//
//  PathDependent.cpp
//  EquityFXMain
//
//  Created by Yuan Wang on 10/4/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#include "PathDependent.h"

PathDependent::PathDependent(const MJArray& LookAtTimes_)
:   LookAtTimes(LookAtTimes_)
{}

const MJArray& PathDependent::GetLookAtTimes() const
{
    return LookAtTimes;
}
