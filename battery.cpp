//
// Created by R-k-l on 2018-12-07.
//

#include "battery.h"
#include <iostream>

Battery::Battery(const string nm, const float volt, const float cst)
    : name(nm),voltage(volt),cost(cst){};
Battery::~Battery() {}
string Battery::getName() const {
    return name;
}
float Battery::getVoltage() const {
    return voltage;
}
float Battery::getCost() const {
    return cost;
}
//______________________________________________

SingleUse::SingleUse(const string name, const float voltage, const float cost, const float capacity)
: Battery(name,voltage,cost),capacity(capacity){};
SingleUse::~SingleUse() {};
string SingleUse::toString() const {
    return getName() + " single use battery";
}
float SingleUse::getLifetimeCost() const {
    return getCost()*getVoltage()*capacity / 1000.0f;
}

Rechargable::Rechargable(const string name, const float voltage, const float cost, const int numCharges,
                         const float capacity)
                         : Battery(name,voltage,cost), numCharges(numCharges),capacity(capacity){};
Rechargable::~Rechargable() {}
string Rechargable::toString() const {
    return getName() + " rechargable battery";
}
float Rechargable::getLifetimeCost() const {
    return getCost()*getVoltage()*capacity / (1000.0f * numCharges);
}
