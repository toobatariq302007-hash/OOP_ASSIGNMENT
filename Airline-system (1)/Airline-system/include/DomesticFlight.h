#ifndef DOMESTIC_FLIGHT_H
#define DOMESTIC_FLIGHT_H

#include "Flight.h"

// Domestic flight - shorter routes, lower base fare, no visa needed
class DomesticFlight : public Flight {
private:
    string region; // e.g., "North", "South"

public:
    DomesticFlight(string fNum, string orig, string dest, string date,
                   string time, int total, int available, string reg);
    ~DomesticFlight();

    // Override pure virtual functions
    double calculateBaseFare() const override;
    void displayDetails() const override;
    string getFlightType() const override;

    string getRegion() const;
    string toFileString() const override;
};

#endif
