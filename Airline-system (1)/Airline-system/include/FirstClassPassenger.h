#ifndef FIRST_CLASS_PASSENGER_H
#define FIRST_CLASS_PASSENGER_H

#include "Passenger.h"

class FirstClassPassenger : public Passenger {
public:
    FirstClassPassenger(string id, string n, string ph, string em);
    ~FirstClassPassenger();

    double getBaggageAllowance() const override;   // 50 kg
    double getLoyaltyMultiplier() const override;   // 2.0x
    double getRefundPercentage() const override;    // 90%
    string getPassengerType() const override;
    void displayInfo() const override;
};

#endif
