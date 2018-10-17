//
//  ExoticBSEnging.h
//  EquityFXMain
//
//  Created by Yuan Wang on 10/4/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#ifndef EXOTIC_BS_ENGINE_H
#define EXOTIC_BS_ENGINE_H
#include "ExoticEngine.h"
#include "Random2.h"

class ExoticBSEngine : public ExoticEngine
{
public:
    ExoticBSEngine(const Wrapper<PathDependent>& TheProduct_,
                   const Parameters& R_,
                   const Parameters& D_,
                   const Parameters& Vol_,
                   const Wrapper<RandomBase>& TheGenerator_,
                   double Spot_);
    virtual void GetOnePath(MJArray& SpotValues);
    virtual ~ExoticBSEngine(){}
private:
    Wrapper<RandomBase> TheGenerator;
    MJArray Drifts;
    MJArray StandardDeviations;
    double LogSpot;
    unsigned long NumberOfTimes;
    MJArray Variates;
};

#endif
