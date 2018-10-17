//
//  PayOffBridge.h
//  VanillaMain3
//
//  Created by Yuan Wang on 9/28/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H
#include "PayOff3.h"

class PayOffBridge
{
public:
    PayOffBridge(const PayOffBridge& original);
    PayOffBridge(const PayOff& innerPayOff);
    inline double operator()(double Spot) const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);
private:
    PayOff* ThePayOffPtr;
};

inline double PayOffBridge::operator()(double Spot) const
{
    return ThePayOffPtr->operator ()(Spot);
}

#endif
