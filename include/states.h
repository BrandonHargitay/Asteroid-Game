//
// Created by Jessie Mejia on 11/22/22.
//

#ifndef CLASSEXAMPLE1122_STATES_H
#define CLASSEXAMPLE1122_STATES_H

#include "../Enums/statesEnum.h"
#include <map>

class states{
private:

    std::map<statesEnum, bool> map;
    void load();
public:
    states();
    bool checkState(statesEnum state) const;
    void enableState(statesEnum state);
    void disableState(statesEnum state);
    void setState(statesEnum state, bool value);
    void toggleState(statesEnum state);
};


#endif //CLASSEXAMPLE1122_STATES_H
