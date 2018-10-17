//
//  ConvergenceTable.cpp
//  StatsMain2.cpp
//
//  Created by Yuan Wang on 9/30/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#include"ConvergenceTable.h" 

ConvergenceTable::ConvergenceTable(const Wrapper<StatisticsMC>& Inner_) : Inner(Inner_)
{
    StoppingPoint=2;
    PathsDone=0;
}

StatisticsMC* ConvergenceTable::clone() const
{
    return new ConvergenceTable(*this);
}

void ConvergenceTable::DumpOneResult(double result)
{
    Inner->DumpOneResult(result); // for all paths, do the routine job which is to record number of path and calculate the average of pricing result (since it is a Monte Carlo process)
    ++PathsDone;
    if (PathsDone == StoppingPoint) // for paths that is power of 2, record the pricing for it and the path number in order to study convergence. 
    {
        StoppingPoint*=2;
        std::vector<std::vector<double>> thisResult(Inner->GetResultsSoFar());
        for (unsigned long i=0; i < thisResult.size(); i++)
        {
            thisResult[i].push_back(PathsDone);
            ResultsSoFar.push_back(thisResult[i]);
        }
    }
    return;
}

std::vector<std::vector<double>> ConvergenceTable::GetResultsSoFar() const
{
    std::vector<std::vector<double> > tmp(ResultsSoFar);
    if (PathsDone*2 != StoppingPoint)
    {
        std::vector<std::vector<double>> thisResult(Inner->GetResultsSoFar());
        for (unsigned long i=0; i < thisResult.size(); i++)
        {
            thisResult[i].push_back(PathsDone);
            tmp.push_back(thisResult[i]);
        }
    }
    return tmp;
}
