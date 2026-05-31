#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <iostream>

using namespace std;

// Ticket class - links a passenger to a flight
class Ticket {
private:
    string ticketID;
    string passengerID;
    string flightNumber;
    string seatNumber;
    double farePaid;
    string bookingStatus; // "Booked", "Cancelled"
    string bookingDate;

public:
    Ticket(string tID, string pID, string fNum, string seat,
           double fare, string status, string bDate);
    ~Ticket();

    // Getters
    string getTicketID() const;
    string getPassengerID() const;
    string getFlightNumber() const;
    string getSeatNumber() const;
    double getFarePaid() const;
    string getBookingStatus() const;
    string getBookingDate() const;

    // Setters
    void setBookingStatus(string status);

    // Operator overloading: == to compare tickets by ID
    bool operator==(const Ticket& other) const;

    // Operator overloading: << for display
    friend ostream& operator<<(ostream& os, const Ticket& ticket);

    // Save to file
    string toFileString() const;
};

#endif
