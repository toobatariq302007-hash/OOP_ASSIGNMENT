#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

using namespace std;

// Custom exception: thrown when trying to book a full flight
class FlightFullException : public exception {
private:
    string message;
public:
    FlightFullException(string flightNum)
        : message("Flight " + flightNum + " is full. No seats available!") {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Custom exception: thrown for invalid cancellation attempts
class InvalidCancellationException : public exception {
private:
    string message;
public:
    InvalidCancellationException(string reason)
        : message("Invalid cancellation: " + reason) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Custom exception: thrown when a duplicate booking is attempted
class DuplicateBookingException : public exception {
private:
    string message;
public:
    DuplicateBookingException(string passengerID, string flightNum)
        : message("Passenger " + passengerID + " already has a ticket on flight " + flightNum) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif
