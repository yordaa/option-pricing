//
//  PricingAsian.cpp
//  Derivative Pricing 10.7.18
//
//  Created by Yuan Wang on 10/9/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#include "PricingAsian.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<double>> pricing_Asian(std::string name,
                                     double expiry, double strike, double spot,
                                     double volatility, double interest, double dividend,
                                     double numberofpaths, double numberofdates)
{
    PayOff* PayOffPtr = PayOffFactory::Instance().CreatePayOff(name,strike); // for digital option, if name is call, change the name here to another notation and build correspondence with name, and add other types to the PayOff class (e.g. calldigital)
    PayOffBridge thePayOff(*PayOffPtr);
    MJArray times(numberofdates); // construct an array to represent dates
    for (unsigned long i=0; i<numberofdates; i++)
        times[i] = (i+1.0)*expiry/numberofdates; // assign value evenly to the dates (how about uneven cases?)
        ParametersConstant VolParam(volatility);
        ParametersConstant rParam(interest);
        ParametersConstant dParam(dividend);
        PathDependentAsian theOption(times, expiry, thePayOff);
        StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    RandomParkMiller generator(numberofdates);
    AntiThetic GenTwo(generator);
    ExoticBSEngine theEngine(theOption, rParam, dParam,
                             VolParam, GenTwo, spot);
    theEngine.DoSimulation(gathererTwo, numberofpaths);
    vector<vector<double>> results = gathererTwo.GetResultsSoFar();
    return results;

}
