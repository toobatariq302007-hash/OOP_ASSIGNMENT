#include "../include/Flight.h"
#include <iomanip>

// Constructor
Flight::Flight(string fNum, string orig, string dest, string date, string time,
               int total, int available)
    : flightNumber(fNum), origin(orig), destination(dest),
      departureDate(date), departureTime(time),
      totalSeats(total), availableSeats(available) {}

// Virtual destructor
Flight::~Flight() {}

// Getters
string Flight::getFlightNumber() const { return flightNumber; }
string Flight::getOrigin() const { return origin; }
string Flight::getDestination() const { return destination; }
string Flight::getDepartureDate() const { return departureDate; }
string Flight::getDepartureTime() const { return departureTime; }
int Flight::getTotalSeats() const { return totalSeats; }
int Flight::getAvailableSeats() const { return availableSeats; }

// Setter
void Flight::setAvailableSeats(int seats) { availableSeats = seats; }

// Book a seat - returns true if successful
bool Flight::bookSeat() {
    if (availableSeats > 0) {
        availableSeats--;
        return true;
    }
    return false;
}

// Cancel a seat - gives back one seat
void Flight::cancelSeat() {
    if (availableSeats < totalSeats) {
        availableSeats++;
    }
}

// Calculate how full the flight is
double Flight::getOccupancyPercentage() const {
    if (totalSeats == 0) return 0.0;
    return ((double)(totalSeats - availableSeats) / totalSeats) * 100.0;
}

// Operator << overloading for easy printing
ostream& operator<<(ostream& os, const Flight& flight) {
    os << "--------------------------------------" << endl;
    os << "Flight Number : " << flight.flightNumber << endl;
    os << "Route         : " << flight.origin << " -> " << flight.destination << endl;
    os << "Date & Time   : " << flight.departureDate << " at " << flight.departureTime << endl;
    os << "Seats         : " << flight.availableSeats << "/" << flight.totalSeats << " available" << endl;
    os << "Base Fare     : $" << fixed << setprecision(2) << flight.calculateBaseFare() << endl;
    os << "Occupancy     : " << fixed << setprecision(1) << flight.getOccupancyPercentage() << "%" << endl;
    os << "--------------------------------------" << endl;
    return os;
}

// Default file string (overridden by derived classes)
string Flight::toFileString() const {
    return flightNumber + "," + origin + "," + destination + "," +
           departureDate + "," + departureTime + "," +
           to_string(totalSeats) + "," + to_string(availableSeats);
}
