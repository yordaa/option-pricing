//
//  PayOffConstructible.h
//  PayFactoryMain
//
//  Created by Yuan Wang on 10/6/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#ifndef PAYOFF_CONSTRUCTIBLE_H
#define PAYOFF_CONSTRUCTIBLE_H
#if defined(_MSC_VER)
#pragma warning(disable : 4786)
#endif
#include "PayOff3.h"
#include "PayOffFactory.h"
#include <iostream>
#include <string>

template <class T>
class PayOffHelper
{
public:
    PayOffHelper(std::string);
    static PayOff* Create(double);
};
template <class T>
PayOff* PayOffHelper<T>::Create(double Strike)
{
    return new T(Strike); // this seems special. PayOffCall has the form PayOffCall(Strike), but not necessary for other cases (e.g. double digital option).
}
template <class T>
PayOffHelper<T>::PayOffHelper(std::string id)
{
    PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
    thePayOffFactory.RegisterPayOff(id,PayOffHelper<T>::Create);
}

#endif
