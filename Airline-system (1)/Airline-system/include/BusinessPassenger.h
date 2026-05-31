#ifndef BUSINESS_PASSENGER_H
#define BUSINESS_PASSENGER_H

#include "Passenger.h"

class BusinessPassenger : public Passenger {
public:
    BusinessPassenger(string id, string n, string ph, string em);
    ~BusinessPassenger();

    double getBaggageAllowance() const override;   // 35 kg
    double getLoyaltyMultiplier() const override;   // 1.5x
    double getRefundPercentage() const override;    // 75%
    string getPassengerType() const override;
    void displayInfo() const override;
};

#endif
