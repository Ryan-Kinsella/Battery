//
// Created by R-k-l on 2018-12-07.
//

#ifndef UNTITLED1_BATTERY_H
#define UNTITLED1_BATTERY_H

#include <string>
using namespace std;

class Battery {
public:
    Battery(const string nm,const float volt,const float cst);
    virtual ~Battery();
    virtual string toString() const = 0;
    virtual float getLifetimeCost() const =0;
    string getName() const;
    float getVoltage() const ;
    float getCost() const ;
private:
    string name;
    float voltage;
    float cost;
};

class SingleUse : public Battery {
public:
    SingleUse(const string name, const float voltage, const float cost,
              const float capacity);
    virtual ~SingleUse();
    virtual string toString() const override;
    virtual float getLifetimeCost() const override;
    //float getCapacity() const;
private:
    float capacity;
};

class Rechargable : public Battery{
public:
    Rechargable(const string name, const float voltage, const float cost,
            const int numCharges, const float capacity);
    virtual ~Rechargable();
    virtual string toString() const override;
    virtual float getLifetimeCost() const override;
    //int getNumCharges() const ;
    //float getCapacity() const ;
private:
    int numCharges;
    float capacity;
};

#endif //UNTITLED1_BATTERY_H
