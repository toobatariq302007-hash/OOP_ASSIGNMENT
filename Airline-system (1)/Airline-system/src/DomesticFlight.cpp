#include "../include/DomesticFlight.h"
#include <iomanip>

DomesticFlight::DomesticFlight(string fNum, string orig, string dest, string date,
                               string time, int total, int available, string reg)
    : Flight(fNum, orig, dest, date, time, total, available), region(reg) {}

DomesticFlight::~DomesticFlight() {}

// Domestic flights have a lower base fare
double DomesticFlight::calculateBaseFare() const {
    return 150.0; // $150 base fare for domestic
}

void DomesticFlight::displayDetails() const {
    cout << "=== DOMESTIC FLIGHT ===" << endl;
    cout << "Flight Number : " << getFlightNumber() << endl;
    cout << "Route         : " << getOrigin() << " -> " << getDestination() << endl;
    cout << "Date & Time   : " << getDepartureDate() << " at " << getDepartureTime() << endl;
    cout << "Region        : " << region << endl;
    cout << "Seats         : " << getAvailableSeats() << "/" << getTotalSeats() << " available" << endl;
    cout << "Base Fare     : $" << fixed << setprecision(2) << calculateBaseFare() << endl;
    cout << "========================" << endl;
}

string DomesticFlight::getFlightType() const {
    return "Domestic";
}

string DomesticFlight::getRegion() const {
    return region;
}

string DomesticFlight::toFileString() const {
    return "Domestic," + Flight::toFileString() + "," + region;
}
