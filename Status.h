//
// Created by Mute on 2022/1/7.
//

#ifndef CONTROLAGENT_STATUS_H
#define CONTROLAGENT_STATUS_H

#include "stdafx.h"

class Status{
public:
    Status();
    bool isExit = false;
    bool isAlive[2] = {false, false};
};


#endif //CONTROLAGENT_STATUS_H
