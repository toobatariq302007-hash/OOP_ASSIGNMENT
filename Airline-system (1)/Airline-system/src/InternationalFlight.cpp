#include "../include/InternationalFlight.h"
#include <iomanip>

InternationalFlight::InternationalFlight(string fNum, string orig, string dest,
                                         string date, string time, int total,
                                         int available, bool visa, string country)
    : Flight(fNum, orig, dest, date, time, total, available),
      visaRequired(visa), destinationCountry(country) {}

InternationalFlight::~InternationalFlight() {}

// International flights have a higher base fare
double InternationalFlight::calculateBaseFare() const {
    return 500.0; // $500 base fare for international
}

void InternationalFlight::displayDetails() const {
    cout << "=== INTERNATIONAL FLIGHT ===" << endl;
    cout << "Flight Number      : " << getFlightNumber() << endl;
    cout << "Route              : " << getOrigin() << " -> " << getDestination() << endl;
    cout << "Date & Time        : " << getDepartureDate() << " at " << getDepartureTime() << endl;
    cout << "Destination Country: " << destinationCountry << endl;
    cout << "Visa Required      : " << (visaRequired ? "Yes" : "No") << endl;
    cout << "Seats              : " << getAvailableSeats() << "/" << getTotalSeats() << " available" << endl;
    cout << "Base Fare          : $" << fixed << setprecision(2) << calculateBaseFare() << endl;
    cout << "=============================" << endl;
}

string InternationalFlight::getFlightType() const {
    return "International";
}

bool InternationalFlight::isVisaRequired() const {
    return visaRequired;
}

string InternationalFlight::getDestinationCountry() const {
    return destinationCountry;
}

string InternationalFlight::toFileString() const {
    return "International," + Flight::toFileString() + "," +
           (visaRequired ? "1" : "0") + "," + destinationCountry;
}
