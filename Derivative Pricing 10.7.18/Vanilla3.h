//
//  Vanilla3.h
//  VanillaMain3
//
//  Created by Yuan Wang on 9/28/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#ifndef VANILLA_3_H
#define VANILLA_3_H

#include"PayOffBridge.h"

class VanillaOption
{
public:
    VanillaOption(const PayOffBridge& ThePayOff_, double Expiry);
    double OptionPayOff(double Spot) const;
    double GetExpiry() const;
private:
    double Expiry;
    PayOffBridge ThePayOff;
};

#endif
