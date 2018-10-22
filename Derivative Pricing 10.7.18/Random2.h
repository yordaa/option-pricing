//
//  Random2.h
//  RandomMain3
//
//  Created by Yuan Wang on 9/30/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#ifndef RANDOM2_H
#define RANDOM2_H
#include "Arrays.h"

class RandomBase
{
public:
    RandomBase(unsigned long Dimensionality);
    virtual ~RandomBase() {};
    inline unsigned long GetDimensionality() const;
    virtual RandomBase* clone() const=0;
    virtual void GetUniforms(MJArray& variates)=0;
    virtual void Skip(unsigned long numberOfPaths)=0;
    virtual void SetSeed(unsigned long Seed) =0;
    virtual void Reset()=0;
    virtual void GetGaussians(MJArray& variates);
    virtual void ResetDimensionality(unsigned long NewDimensionality);
private:
    unsigned long Dimensionality;
};

unsigned long RandomBase::GetDimensionality() const
{
    return Dimensionality;
}

#endif
