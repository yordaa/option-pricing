//
//  ConvergenceTable.h
//  StatsMain2.cpp
//
//  Created by Yuan Wang on 9/30/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#ifndef CONVERGENCE_TABLE_H
#define CONVERGENCE_TABLE_H
#include "MCStatistics.h"
#include "Wrapper.h"

class ConvergenceTable : public StatisticsMC
{
public:
    ConvergenceTable(const Wrapper<StatisticsMC>& Inner_);
    virtual StatisticsMC* clone() const;
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar() const;
private:
    Wrapper<StatisticsMC> Inner;
    std::vector<std::vector<double>> ResultsSoFar;
    unsigned long StoppingPoint;
    unsigned long PathsDone;
};

#endif
