#ifndef INTERNATIONAL_FLIGHT_H
#define INTERNATIONAL_FLIGHT_H

#include "Flight.h"

// International flight - longer routes, higher fare, visa requirements
class InternationalFlight : public Flight {
private:
    bool visaRequired;
    string destinationCountry;

public:
    InternationalFlight(string fNum, string orig, string dest, string date,
                        string time, int total, int available,
                        bool visa, string country);
    ~InternationalFlight();

    double calculateBaseFare() const override;
    void displayDetails() const override;
    string getFlightType() const override;

    bool isVisaRequired() const;
    string getDestinationCountry() const;
    string toFileString() const override;
};

#endif
