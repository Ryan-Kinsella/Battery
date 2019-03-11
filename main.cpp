#include "battery.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
using namespace std;
int main() {
    vector<unique_ptr<Battery>> bats;
    // make_unique invokes the constructors
    bats.push_back(make_unique<SingleUse>("Alkaline D", 1.5, 100, 8.0));
    bats.push_back(make_unique<SingleUse>("Alkaline 9V", 9.0, 600, 0.4));
    bats.push_back(make_unique<SingleUse>("Silver Oxide Button", 1.55, 18000,
                                          0.15));
    bats.push_back(make_unique<Rechargable>("Lead Acid", 2.1, 100, 225, 500));
    bats.push_back(make_unique<Rechargable>("NiCad", 1.2, 1000, 1.0, 500));
    bats.push_back(make_unique<Rechargable>("LiPo", 3.2, 350, 2.2, 1000));
    for (unsigned int i = 0; i < bats.size(); i++) {
        cout << bats[i]->toString();
        cout << fixed << setprecision(3) << ", cost per use: $" <<
             bats[i]->getLifetimeCost() << endl;
    }
    return 0;
}


