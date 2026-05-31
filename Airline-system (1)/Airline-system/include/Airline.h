#ifndef AIRLINE_H
#define AIRLINE_H

#include <vector>
#include <map>
#include <memory>
#include <string>

#include "Flight.h"
#include "DomesticFlight.h"
#include "InternationalFlight.h"
#include "CharterFlight.h"
#include "Passenger.h"
#include "EconomyPassenger.h"
#include "BusinessPassenger.h"
#include "FirstClassPassenger.h"
#include "Ticket.h"
#include "Exceptions.h"
#include "SearchUtility.h"

using namespace std;

// Main Airline class - aggregates flights, passengers, and tickets
class Airline {
private:
    string airlineName;
    vector<shared_ptr<Flight>> flights;
    vector<shared_ptr<Passenger>> passengers;
    vector<Ticket> tickets;
    map<string, double> revenueByFlight; // flightNumber -> total revenue
    int nextTicketID;

    // Helper to generate ticket IDs
    string generateTicketID();

public:
    Airline(string name);
    ~Airline();

    // ---- Flight Management ----
    void addFlight(shared_ptr<Flight> flight);
    bool removeFlight(const string& flightNumber);
    vector<shared_ptr<Flight>> searchFlightsByNumber(const string& flightNum);
    vector<shared_ptr<Flight>> searchFlightsByRoute(const string& origin, const string& dest);
    vector<shared_ptr<Flight>> searchFlightsByDate(const string& date);
    void listAllFlights() const;

    // ---- Passenger Management ----
    void registerPassenger(shared_ptr<Passenger> passenger);
    bool removePassenger(const string& passengerID);
    void viewBookingHistory(const string& passengerID) const;
    shared_ptr<Passenger> findPassenger(const string& passengerID);

    // ---- Booking ----
    void bookTicket(const string& passengerID, const string& flightNumber, const string& currentDate);

    // ---- Cancellation & Refund ----
    void cancelTicket(const string& ticketID, const string& currentDate);

    // ---- Reports ----
    void todaysDepartures(const string& today) const;
    void occupancyReport() const;
    void topRevenueFlights() const;

    // ---- Persistence (File I/O) ----
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);

    // ---- Getters ----
    const vector<shared_ptr<Flight>>& getFlights() const;
    const vector<shared_ptr<Passenger>>& getPassengers() const;
    const vector<Ticket>& getTickets() const;
};

#endif
