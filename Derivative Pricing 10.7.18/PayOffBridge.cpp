//
//  PayOffBridge.cpp
//  VanillaMain3
//
//  Created by Yuan Wang on 9/28/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#include"PayOffBridge.h"

PayOffBridge::PayOffBridge(const PayOffBridge& original)
{
    ThePayOffPtr = original.ThePayOffPtr->clone();
}
PayOffBridge::PayOffBridge(const PayOff& innerPayOff)
{
    ThePayOffPtr = innerPayOff.clone();
}
PayOffBridge::~PayOffBridge()
{
    delete ThePayOffPtr;
}
PayOffBridge& PayOffBridge::operator=
(const PayOffBridge& original)
{
    if (this != &original)
    {
        delete ThePayOffPtr;
        ThePayOffPtr = original.ThePayOffPtr->clone();
    }
    return *this;
}
