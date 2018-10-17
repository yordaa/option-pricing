//
//  main.cpp
//  Derivative Pricing 10.7.18
//
//  Created by Yuan Wang on 10/7/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#include"SimpleMC7.h"
#include"Vanilla3.h"
#include"MCStatistics.h"
#include "PayOffConstructible.h"
#include "PayOffBridge.h"
#include "PayOffFactory.h"
#include "PricingVanilla.h"
#include "PricingDigital.h"
#include "PricingDoubleDigital.h"
#include "PricingAsian.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> callorput = {"call", "put"};
    vector<string> typelist = {"vanilla", "digital", "double digital", "Asian"};
    map<string, vector<string>> type_to_prmt;
        type_to_prmt["vanilla"] = {"Expiry", "Strike", "Spot", "Volatility", "Interest", "Number of Paths"};
        type_to_prmt["digital"] = {"Expiry", "Strike", "Spot", "Volatility", "Interest", "Number of Paths"};
        type_to_prmt["double digital"] = {"Expiry", "Upper Strike", "Lower Strike", "Spot", "Volatility", "Interest", "Number of Paths"};
        type_to_prmt["Asian"] = {"Expiry", "Strike", "Spot", "Dividend", "Volatility", "Interest", "Number of Paths", "Number of Dates"};
    map<string, double> assign_prmt_val;
    
    int j=-1,k;
    
    cout << "\nPlease enter the corresponding number for the type of the option you would like to evaluate. Current available choices are:" << endl;
    for (int i = 0; i < typelist.size(); ++i) {
        cout << i+1 << "." << typelist[i] << endl;
    }
    cin >> k;
    if (k!=3) {
        cout << "\nWould you like to price a call or put option? Please choose the corresponding number. \n";
        for (int i = 0; i < callorput.size(); ++i) {
            cout << i+1 << "." << callorput[i] << endl;
        }
        
        cin >> j;
        while (j!=1 && j!=2) {
            cout << "Valid number please:)\n";
            cin >> j;
        }
    }    
    cout << "\nFor your choice, you will need to give the following parameters:" << endl;
    for (int i = 0; i<type_to_prmt[typelist[k-1]].size(); ++i) {
        cout << type_to_prmt[typelist[k-1]][i] << endl;
    }
    cout << "\n";
    for (int i = 0; i<type_to_prmt[typelist[k-1]].size(); ++i) {
        cout << "Please enter the " << type_to_prmt[typelist[k-1]][i] << endl;
        cin >> assign_prmt_val[type_to_prmt[typelist[k-1]][i]];
    }
//    switch (j) {
//        case 1:
//            PayOffCall thePayOff(assign_prmt_val["Strike"]);
//        case 2:
//            PayOffPut thePayOff(assign_prmt_val["Strike"]);            
//    }
    
//    PayOff* PayOffPtr = PayOffFactory::Instance().CreatePayOff(callorput[j-1],assign_prmt_val["Strike"]);
//    PayOffBridge thePayOff(*PayOffPtr);
//    VanillaOption theOption(thePayOff, assign_prmt_val["Expiry"]);
//    ParametersConstant VolParam(assign_prmt_val["Volatility"]);
//    ParametersConstant rParam(assign_prmt_val["Interest"]);
//    StatisticsMean gatherer;
//    SimpleMonteCarlo5(theOption,
//                      assign_prmt_val["Spot"],
//                      VolParam,
//                      rParam,
//                      assign_prmt_val["Number of Paths"],
//                      gatherer);
    vector<vector<double>> results;
    switch (k) {
        case 1:
            results = pricing_vanilla(callorput[j-1],
                                      assign_prmt_val["Expiry"],
                                      assign_prmt_val["Strike"],
                                      assign_prmt_val["Spot"],
                                      assign_prmt_val["Volatility"],
                                      assign_prmt_val["Interest"],
                                      assign_prmt_val["Number of Paths"]);
            break;
        case 2:
            results = pricing_digital(callorput[j-1],
                                      assign_prmt_val["Expiry"],
                                      assign_prmt_val["Strike"],
                                      assign_prmt_val["Spot"],
                                      assign_prmt_val["Volatility"],
                                      assign_prmt_val["Interest"],
                                      assign_prmt_val["Number of Paths"]);
            break;
        case 3:
            results = pricing_double_digital(assign_prmt_val["Expiry"],
                                      assign_prmt_val["Upper Strike"],
                                      assign_prmt_val["Lower Strike"],
                                      assign_prmt_val["Spot"],
                                      assign_prmt_val["Volatility"],
                                      assign_prmt_val["Interest"],
                                      assign_prmt_val["Number of Paths"]);
            break;
        case 4:
            results = pricing_Asian(callorput[j-1],
                                    assign_prmt_val["Expiry"],
                                    assign_prmt_val["Strike"],
                                    assign_prmt_val["Spot"],
                                    assign_prmt_val["Dividend"],
                                    assign_prmt_val["Volatility"],
                                    assign_prmt_val["Interest"],
                                    assign_prmt_val["Number of Paths"],
                                    assign_prmt_val["Number of Dates"]);
            break;
        default:
            cout << "Error.\n";
            break;
    }
    
    cout <<"\nThe pricing result is \n";
    for (unsigned long m=0; m < results.size(); m++)
    {
        for (unsigned long n=0; n < results[m].size(); n++)
            cout << results[m][n] << " ";
        cout << "\n";
    }
    return 0;
}
