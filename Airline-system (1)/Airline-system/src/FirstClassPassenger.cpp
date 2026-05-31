#include "../include/FirstClassPassenger.h"

FirstClassPassenger::FirstClassPassenger(string id, string n, string ph, string em)
    : Passenger(id, n, ph, em) {}

FirstClassPassenger::~FirstClassPassenger() {}

double FirstClassPassenger::getBaggageAllowance() const {
    return 50.0; // 50 kg for first class
}

double FirstClassPassenger::getLoyaltyMultiplier() const {
    return 2.0; // 2x multiplier
}

double FirstClassPassenger::getRefundPercentage() const {
    return 90.0; // 90% refund
}

string FirstClassPassenger::getPassengerType() const {
    return "FirstClass";
}

void FirstClassPassenger::displayInfo() const {
    cout << "=== FIRST CLASS PASSENGER ===" << endl;
    Passenger::displayInfo();
    cout << "Baggage       : " << getBaggageAllowance() << " kg" << endl;
    cout << "Refund Rate   : " << getRefundPercentage() << "%" << endl;
    cout << "==============================" << endl;
}
