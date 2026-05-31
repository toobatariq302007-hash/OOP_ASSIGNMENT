#include "../include/Ticket.h"
#include <iomanip>

Ticket::Ticket(string tID, string pID, string fNum, string seat,
               double fare, string status, string bDate)
    : ticketID(tID), passengerID(pID), flightNumber(fNum),
      seatNumber(seat), farePaid(fare), bookingStatus(status),
      bookingDate(bDate) {}

Ticket::~Ticket() {}

// Getters
string Ticket::getTicketID() const { return ticketID; }
string Ticket::getPassengerID() const { return passengerID; }
string Ticket::getFlightNumber() const { return flightNumber; }
string Ticket::getSeatNumber() const { return seatNumber; }
double Ticket::getFarePaid() const { return farePaid; }
string Ticket::getBookingStatus() const { return bookingStatus; }
string Ticket::getBookingDate() const { return bookingDate; }

// Setter
void Ticket::setBookingStatus(string status) { bookingStatus = status; }

// Operator == : compare tickets by their ID
bool Ticket::operator==(const Ticket& other) const {
    return this->ticketID == other.ticketID;
}

// Operator << : display ticket info
ostream& operator<<(ostream& os, const Ticket& ticket) {
    os << "--------------------------------------" << endl;
    os << "Ticket ID     : " << ticket.ticketID << endl;
    os << "Passenger ID  : " << ticket.passengerID << endl;
    os << "Flight Number : " << ticket.flightNumber << endl;
    os << "Seat Number   : " << ticket.seatNumber << endl;
    os << "Fare Paid     : $" << fixed << setprecision(2) << ticket.farePaid << endl;
    os << "Status        : " << ticket.bookingStatus << endl;
    os << "Booking Date  : " << ticket.bookingDate << endl;
    os << "--------------------------------------" << endl;
    return os;
}

// Save to file
string Ticket::toFileString() const {
    return ticketID + "," + passengerID + "," + flightNumber + "," +
           seatNumber + "," + to_string(farePaid) + "," +
           bookingStatus + "," + bookingDate;
}
