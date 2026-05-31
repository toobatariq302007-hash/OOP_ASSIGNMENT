#include "../include/BusinessPassenger.h"

BusinessPassenger::BusinessPassenger(string id, string n, string ph, string em)
    : Passenger(id, n, ph, em) {}

BusinessPassenger::~BusinessPassenger() {}

double BusinessPassenger::getBaggageAllowance() const {
    return 35.0; // 35 kg for business
}

double BusinessPassenger::getLoyaltyMultiplier() const {
    return 1.5; // 1.5x multiplier
}

double BusinessPassenger::getRefundPercentage() const {
    return 75.0; // 75% refund
}

string BusinessPassenger::getPassengerType() const {
    return "Business";
}

void BusinessPassenger::displayInfo() const {
    cout << "=== BUSINESS PASSENGER ===" << endl;
    Passenger::displayInfo();
    cout << "Baggage       : " << getBaggageAllowance() << " kg" << endl;
    cout << "Refund Rate   : " << getRefundPercentage() << "%" << endl;
    cout << "==========================" << endl;
}
