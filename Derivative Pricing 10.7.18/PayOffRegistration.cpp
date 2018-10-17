//
//  PayOffRegistration.cpp
//  PayFactoryMain
//
//  Created by Yuan Wang on 10/6/18.
//  Copyright © 2018 Yuan Wang. All rights reserved.
//

#include "PayOffConstructible.h"

namespace {
    PayOffHelper<PayOffCall> RegisterCall("call"); // it means we register an object named "call" as type PayOffHelper<PayOffCall>. I think we can replace the RegisterCall by another name and it still works.
    PayOffHelper<PayOffPut> RegisterPut("put");
    PayOffHelper<PayOffCallDigital> RegisterCallDigital("calldigital");
    PayOffHelper<PayOffPutDigital> RegisterPutDigital("putdigital");
//    PayOffHelper<PayOffDoubleDigital> RegisterDoubleDigital("doubledigital");
}
