//
//  Vanilla3.cpp
//  VanillaMain3
//
//  Created by Yuan Wang on 9/28/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#include "Vanilla3.h"

VanillaOption::VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_)
:  ThePayOff(ThePayOff_), Expiry(Expiry_)
{ }

double VanillaOption::GetExpiry() const
{
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
    return ThePayOff(Spot);
}
