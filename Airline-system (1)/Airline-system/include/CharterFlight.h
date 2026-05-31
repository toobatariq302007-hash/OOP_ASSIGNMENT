#ifndef CHARTER_FLIGHT_H
#define CHARTER_FLIGHT_H

#include "Flight.h"

// Charter flight - hired by a company/person, fixed contract price
class CharterFlight : public Flight {
private:
    string contractHolder; // company or person who chartered the flight
    double contractPrice;  // total contract price

public:
    CharterFlight(string fNum, string orig, string dest, string date,
                  string time, int total, int available,
                  string holder, double price);
    ~CharterFlight();

    double calculateBaseFare() const override;
    void displayDetails() const override;
    string getFlightType() const override;

    string getContractHolder() const;
    double getContractPrice() const;
    string toFileString() const override;
};

#endif
