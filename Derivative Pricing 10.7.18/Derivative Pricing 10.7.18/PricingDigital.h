//
//  PricingDigital.h
//  Derivative Pricing 10.7.18
//
//  Created by Yuan Wang on 10/9/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#ifndef PricingDigital_h
#define PricingDigital_h

#include "Vanilla3.h"
#include "PayOff3.h"
#include "PayOffBridge.h"
#include "Parameters.h"
#include "MCStatistics.h"
#include "SimpleMC7.h"
#include "PayOffFactory.h"

std::vector<std::vector<double>> pricing_digital(std::string name, double expiry, double strike, double spot,
                                                 double volatility, double interest, double numberofpaths);

#endif /* PricingDigital_h */
