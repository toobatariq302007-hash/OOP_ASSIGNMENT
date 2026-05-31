#ifndef ECONOMY_PASSENGER_H
#define ECONOMY_PASSENGER_H

#include "Passenger.h"

class EconomyPassenger : public Passenger {
public:
    EconomyPassenger(string id, string n, string ph, string em);
    ~EconomyPassenger();

    double getBaggageAllowance() const override;   // 20 kg
    double getLoyaltyMultiplier() const override;   // 1.0x
    double getRefundPercentage() const override;    // 50%
    string getPassengerType() const override;
    void displayInfo() const override;
};

#endif
