//
//  ExoticEngine.h
//  EquityFXMain
//
//  Created by Yuan Wang on 10/4/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#ifndef EXOTIC_ENGINE_H
#define EXOTIC_ENGINE_H
#include "Wrapper.h"
#include "Parameters.h"
#include "PathDependent.h"
#include "MCStatistics.h"
#include <vector>

class ExoticEngine
{
public:
    ExoticEngine(const Wrapper<PathDependent>& TheProduct_, const Parameters& r_);
    virtual void GetOnePath(MJArray& SpotValues)=0;
    void DoSimulation(StatisticsMC& TheGatherer,
                      unsigned long NumberOfPaths);
    virtual ~ExoticEngine(){}
    double DoOnePath(const MJArray& SpotValues) const;
private:
    Wrapper<PathDependent> TheProduct;
    Parameters r;
    MJArray Discounts;
    mutable std::vector<CashFlow> TheseCashFlows;
};

#endif
