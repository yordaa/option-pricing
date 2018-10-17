//
//  PricingDoubleDigital.cpp
//  Derivative Pricing 10.7.18
//
//  Created by Yuan Wang on 10/9/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#include "PricingDoubleDigital.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<double>> pricing_double_digital(double expiry, double upperstrike, double lowerstrike, double spot,
                                              double volatility, double interest, double numberofpaths)
{
    PayOffDoubleDigital thePayOff(upperstrike, lowerstrike);
    VanillaOption theOption(thePayOff, expiry);
    ParametersConstant VolParam(volatility);
    ParametersConstant rParam(interest);
    StatisticsMean gatherer;
    SimpleMonteCarlo5(theOption,
                      spot,
                      VolParam,
                      rParam,
                      numberofpaths,
                      gatherer);
    vector<vector<double>> results = gatherer.GetResultsSoFar();
    return results;
}

