//
// Created by Jessie Mejia on 11/22/22.
//

#include "../include/states.h"

bool states::checkState(statesEnum state) const {
    return map.at(state);
}

void states::enableState(statesEnum state) {
    setState(state,true);
}

void states::disableState(statesEnum state) {
    setState(state,false);
}

void states::setState(statesEnum state, bool value) {
    map.at(state) = value;
}

void states::toggleState(statesEnum state) {
    setState(state, !map.at(state));
}

states::states() {
    load();
}

void states::load() {
    for (int i = 0; i < LAST_STATE; i++)
    {
        map[static_cast<statesEnum>(i)] = false;
    }
}

