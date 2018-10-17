//
//  Payoff3.h
//  VanillaMain2
//
//  Created by Yuan Wang on 9/27/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#ifndef PAYOFF3_H
#define PAYOFF3_H

// adapt the clone method so that a payoff class integrates type and expiry and the class can be copied withought knowing its type

class PayOff
{
public:
    PayOff(){};
    virtual double operator()(double Spot) const=0;
    virtual ~PayOff(){}
    virtual PayOff* clone() const=0;
    private:
};

class PayOffCall : public PayOff
{
public:
    PayOffCall(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall(){}
    virtual PayOff* clone() const;
private:
    double Strike;
};

class PayOffPut : public PayOff
{
public:
    PayOffPut(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut(){}
    virtual PayOff* clone() const;
private:
    double Strike;
};

class PayOffCallDigital : public PayOff
{
public:
    PayOffCallDigital(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffCallDigital(){}
    virtual PayOff* clone() const;
private:
    double Strike;
};

class PayOffPutDigital : public PayOff
{
public:
    PayOffPutDigital(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffPutDigital(){}
    virtual PayOff* clone() const;
private:
    double Strike;
};

class PayOffDoubleDigital : public PayOff
{
public:
    PayOffDoubleDigital(double UpperStrike_, double LowerStrike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital(){}
    virtual PayOff* clone() const;
private:
    double UpperStrike;
    double LowerStrike;
};

#endif
