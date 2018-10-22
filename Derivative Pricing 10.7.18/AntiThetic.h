//
//  AntiThetic.h
//  RandomMain3
//
//  Created by Yuan Wang on 9/30/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#ifndef ANTITHETIC_H
#define ANTITHETIC_H
#include "Random2.h"
#include "Wrapper.h"

class AntiThetic : public RandomBase
{
public:
    AntiThetic(const Wrapper<RandomBase>& innerGenerator );
    virtual RandomBase* clone() const;
    virtual void GetUniforms(MJArray& variates);
    virtual void Skip(unsigned long numberOfPaths);
    virtual void SetSeed(unsigned long Seed);
    virtual void ResetDimensionality(unsigned long NewDimensionality);
    virtual void Reset();
private:
    Wrapper<RandomBase> InnerGenerator;
    bool OddEven;
    MJArray NextVariates;
};

#endif
