//
//  PricingDigital.cpp
//  Derivative Pricing 10.7.18
//
//  Created by Yuan Wang on 10/9/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#include "PricingDigital.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<double>> pricing_digital(string name, double expiry, double strike, double spot,
                                       double volatility, double interest, double numberofpaths)
{
    string subname;
    if (name == "call") {
        subname = "calldigital";
    }
    else if (name == "put") {
        subname = "putdigital";
    }
    PayOff* PayOffPtr = PayOffFactory::Instance().CreatePayOff(subname,strike); // for digital option, if name is call, change the name here to another notation and build correspondence with name, and add other types to the PayOff class (e.g. calldigital)
    PayOffBridge thePayOff(*PayOffPtr);
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

