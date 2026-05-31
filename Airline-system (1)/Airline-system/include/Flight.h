#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <iostream>

using namespace std;

// Abstract base class for all flight types
class Flight {
protected:
    string flightNumber;
    string origin;
    string destination;
    string departureDate; // format: YYYY-MM-DD
    string departureTime; // format: HH:MM
    int totalSeats;
    int availableSeats;

public:
    // Constructor
    Flight(string fNum, string orig, string dest, string date, string time,
           int total, int available);

    // Virtual destructor for proper cleanup
    virtual ~Flight();

    // Pure virtual functions (make this class abstract)
    virtual double calculateBaseFare() const = 0;
    virtual void displayDetails() const = 0;
    virtual string getFlightType() const = 0;

    // Getters
    string getFlightNumber() const;
    string getOrigin() const;
    string getDestination() const;
    string getDepartureDate() const;
    string getDepartureTime() const;
    int getTotalSeats() const;
    int getAvailableSeats() const;

    // Setters
    void setAvailableSeats(int seats);

    // Book a seat (decreases available seats)
    bool bookSeat();
    // Cancel a seat (increases available seats)
    void cancelSeat();

    // Calculate occupancy percentage
    double getOccupancyPercentage() const;

    // Operator overloading: << for display
    friend ostream& operator<<(ostream& os, const Flight& flight);

    // Save/Load for file persistence
    virtual string toFileString() const;
};

#endif
