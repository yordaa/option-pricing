//
//  PricingAsian.h
//  Derivative Pricing 10.7.18
//
//  Created by Yuan Wang on 10/9/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#ifndef PricingAsian_h
#define PricingAsian_h

#include"ParkMiller.h"
#include"MCStatistics.h"
#include"ConvergenceTable.h"
#include"AntiThetic.h"
#include"PathDependentAsian.h"
#include"ExoticBSEngine.h"
#include "PayOffFactory.h"

std::vector<std::vector<double>> pricing_Asian(std::string name,
                                                        double expiry, double strike, double spot,
                                                        double volatility, double interest, double dividend,
                                                        double numberofpaths, double numberofdates);

#endif /* PricingAsian_h */
