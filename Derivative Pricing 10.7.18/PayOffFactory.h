//
//  PayOffFactory.h
//  PayFactoryMain
//
//  Created by Yuan Wang on 10/6/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#ifndef PAYOFF_FACTORY_H
#define PAYOFF_FACTORY_H
#include "PayOff3.h"
#if defined(_MSC_VER)
#pragma warning( disable : 4786)
#endif
#include <map>
#include <string>

class PayOffFactory
{
public:
    typedef PayOff* (*CreatePayOffFunction)(double );
    static PayOffFactory& Instance();
    void RegisterPayOff(std::string, CreatePayOffFunction);
    PayOff* CreatePayOff(std::string PayOffId,double Strike);
    ~PayOffFactory(){};
private:
    std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
    PayOffFactory(){}
    PayOffFactory(const PayOffFactory&){}
    PayOffFactory& operator=(const PayOffFactory&){return *this;}
};

#endif
