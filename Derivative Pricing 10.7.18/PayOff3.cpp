//
//  Payoff3.cpp
//  VanillaMain2
//
//  Created by Yuan Wang on 9/27/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#include"PayOff3.h"
#include<algorithm>

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
}
double PayOffCall::operator () (double Spot) const
{
    return std::max(Spot-Strike,0.0);
}
PayOff* PayOffCall::clone() const
{
    return new PayOffCall(*this);
}

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_)
{
}
double PayOffPut::operator () (double Spot) const
{
    return std::max(Strike-Spot,0.0);
}
PayOff* PayOffPut::clone() const
{
    return new PayOffPut(*this);
}

PayOffCallDigital::PayOffCallDigital(double Strike_) : Strike(Strike_)
{
}
double PayOffCallDigital::operator () (double Spot) const
{
    return (Spot>Strike?1.0:0.0);
}
PayOff* PayOffCallDigital::clone() const
{
    return new PayOffCallDigital(*this);
}

PayOffPutDigital::PayOffPutDigital(double Strike_) : Strike(Strike_)
{
}
double PayOffPutDigital::operator () (double Spot) const
{
    return (Spot<Strike?1.0:0.0);
}
PayOff* PayOffPutDigital::clone() const
{
    return new PayOffPutDigital(*this);
}

PayOffDoubleDigital::PayOffDoubleDigital(double UpperStrike_, double LowerStrike_)
: UpperStrike(UpperStrike_), LowerStrike(LowerStrike_)
{
}
double PayOffDoubleDigital::operator () (double Spot) const
{
    return (Spot<UpperStrike && Spot>LowerStrike)?1.0:0.0;
}
PayOff* PayOffDoubleDigital::clone() const
{
    return new PayOffDoubleDigital(*this);
}

