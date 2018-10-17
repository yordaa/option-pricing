//
//  SimpleMC7.h
//  StatsMain1
//
//  Created by Yuan Wang on 9/29/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#ifndef SIMPLEMC7_H
#define SIMPLEMC7_H
#include "Vanilla3.h"
#include "Parameters.h"
#include "MCStatistics.h"

void SimpleMonteCarlo5(const VanillaOption& TheOption,
                       double Spot,
                       const Parameters& Vol,
                       const Parameters& r,
                       unsigned long NumberOfPaths,
                       StatisticsMC& gatherer);

#endif
