/*
 * =========================================================
 *  SkyLink Airways - Airline Reservation & Flight Management
 *  Console-Based C++ Application
 *  OOP Assignment
 * =========================================================
 */

#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include <ctime>

#include "../include/Airline.h"

using namespace std;

// Helper function to get today's date as YYYY-MM-DD string
string getCurrentDate() {
    time_t now = time(0);
    struct tm* timeInfo = localtime(&now);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeInfo);
    return string(buffer);
}

// Helper function to safely read an integer from cin
// Returns true if successful, false if bad input
bool safeReadInt(int& value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a number." << endl;
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

// Helper function to safely read a double from cin
bool safeReadDouble(double& value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a number." << endl;
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

// Function to clear input buffer after bad input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to load sample data (10 flights + 8 passengers)
void loadSampleData(Airline& airline) {
    cout << "\nLoading sample data..." << endl;

    // ---- 10 Sample Flights ----

    // Domestic Flights
    airline.addFlight(make_shared<DomesticFlight>(
        "SL101", "Karachi", "Lahore", "2026-05-30", "08:00", 150, 150, "South"));
    airline.addFlight(make_shared<DomesticFlight>(
        "SL102", "Lahore", "Islamabad", "2026-05-30", "10:30", 120, 120, "North"));
    airline.addFlight(make_shared<DomesticFlight>(
        "SL103", "Islamabad", "Karachi", "2026-05-31", "14:00", 180, 180, "Central"));
    airline.addFlight(make_shared<DomesticFlight>(
        "SL104", "Peshawar", "Karachi", "2026-06-01", "07:00", 100, 100, "North"));

    // International Flights
    airline.addFlight(make_shared<InternationalFlight>(
        "SL201", "Karachi", "Dubai", "2026-05-30", "12:00", 200, 200, true, "UAE"));
    airline.addFlight(make_shared<InternationalFlight>(
        "SL202", "Lahore", "London", "2026-05-31", "22:00", 250, 250, true, "UK"));
    airline.addFlight(make_shared<InternationalFlight>(
        "SL203", "Islamabad", "Istanbul", "2026-06-01", "09:00", 180, 180, false, "Turkey"));

    // Charter Flights
    airline.addFlight(make_shared<CharterFlight>(
        "SL301", "Karachi", "Skardu", "2026-05-30", "06:00", 50, 50, "TrekCorp", 25000.0));
    airline.addFlight(make_shared<CharterFlight>(
        "SL302", "Lahore", "Gilgit", "2026-06-02", "05:30", 40, 40, "MountainAir", 20000.0));
    airline.addFlight(make_shared<CharterFlight>(
        "SL303", "Islamabad", "Chitral", "2026-06-03", "07:00", 30, 30, "NorthExp", 15000.0));

    // ---- 8 Sample Passengers ----

    airline.registerPassenger(make_shared<EconomyPassenger>(
        "P001", "Ali Ahmed", "0300-1234567", "ali@email.com"));
    airline.registerPassenger(make_shared<EconomyPassenger>(
        "P002", "Sara Khan", "0321-9876543", "sara@email.com"));
    airline.registerPassenger(make_shared<EconomyPassenger>(
        "P003", "Usman Malik", "0333-5551234", "usman@email.com"));

    airline.registerPassenger(make_shared<BusinessPassenger>(
        "P004", "Fatima Noor", "0312-7778899", "fatima@email.com"));
    airline.registerPassenger(make_shared<BusinessPassenger>(
        "P005", "Hassan Raza", "0345-1112233", "hassan@email.com"));

    airline.registerPassenger(make_shared<FirstClassPassenger>(
        "P006", "Ayesha Siddiqui", "0300-4445566", "ayesha@email.com"));
    airline.registerPassenger(make_shared<FirstClassPassenger>(
        "P007", "Bilal Tariq", "0321-6667788", "bilal@email.com"));
    airline.registerPassenger(make_shared<FirstClassPassenger>(
        "P008", "Zara Iqbal", "0333-8889900", "zara@email.com"));

    cout << "Sample data loaded successfully!\n" << endl;
}

// Display main menu
void displayMenu() {
    cout << "\n============================================" << endl;
    cout << "   SKYLINK AIRWAYS - Management System" << endl;
    cout << "============================================" << endl;
    cout << "  1.  Add Flight" << endl;
    cout << "  2.  Remove Flight" << endl;
    cout << "  3.  Search Flights" << endl;
    cout << "  4.  List All Flights" << endl;
    cout << "  5.  Register Passenger" << endl;
    cout << "  6.  Remove Passenger" << endl;
    cout << "  7.  View Passenger Booking History" << endl;
    cout << "  8.  Book a Ticket" << endl;
    cout << "  9.  Cancel a Ticket" << endl;
    cout << "  10. Today's Departures" << endl;
    cout << "  11. Occupancy Report" << endl;
    cout << "  12. Top 5 Revenue Flights" << endl;
    cout << "  13. Load Sample Data" << endl;
    cout << "  14. Save & Exit" << endl;
    cout << "============================================" << endl;
    cout << "Enter your choice: ";
}

// Add a new flight through user input
void handleAddFlight(Airline& airline) {
    cout << "\n--- Add New Flight ---" << endl;
    cout << "Select flight type:" << endl;
    cout << "1. Domestic" << endl;
    cout << "2. International" << endl;
    cout << "3. Charter" << endl;
    cout << "Choice: ";

    int type;
    if (!safeReadInt(type)) return;

    string fNum, orig, dest, date, time;
    int seats;

    cout << "Flight Number: ";
    getline(cin, fNum);
    cout << "Origin: ";
    getline(cin, orig);
    cout << "Destination: ";
    getline(cin, dest);
    cout << "Departure Date (YYYY-MM-DD): ";
    getline(cin, date);
    cout << "Departure Time (HH:MM): ";
    getline(cin, time);
    cout << "Total Seats: ";
    if (!safeReadInt(seats)) return;

    if (type == 1) {
        string region;
        cout << "Region (e.g., North, South): ";
        getline(cin, region);
        airline.addFlight(make_shared<DomesticFlight>(
            fNum, orig, dest, date, time, seats, seats, region));

    } else if (type == 2) {
        string country;
        int visa;
        cout << "Destination Country: ";
        getline(cin, country);
        cout << "Visa Required? (1=Yes, 0=No): ";
        if (!safeReadInt(visa)) return;
        airline.addFlight(make_shared<InternationalFlight>(
            fNum, orig, dest, date, time, seats, seats, (visa == 1), country));

    } else if (type == 3) {
        string holder;
        double price;
        cout << "Contract Holder: ";
        getline(cin, holder);
        cout << "Contract Price: $";
        if (!safeReadDouble(price)) return;
        airline.addFlight(make_shared<CharterFlight>(
            fNum, orig, dest, date, time, seats, seats, holder, price));

    } else {
        cout << "Invalid flight type!" << endl;
    }
}

// Remove a flight
void handleRemoveFlight(Airline& airline) {
    cout << "\n--- Remove Flight ---" << endl;
    string fNum;
    cout << "Enter Flight Number to remove: ";
    getline(cin, fNum);
    airline.removeFlight(fNum);
}

// Search flights
void handleSearchFlights(Airline& airline) {
    cout << "\n--- Search Flights ---" << endl;
    cout << "Search by:" << endl;
    cout << "1. Flight Number" << endl;
    cout << "2. Route (Origin & Destination)" << endl;
    cout << "3. Date" << endl;
    cout << "Choice: ";

    int choice;
    if (!safeReadInt(choice)) return;

    vector<shared_ptr<Flight>> results;

    if (choice == 1) {
        string fNum;
        cout << "Enter Flight Number: ";
        getline(cin, fNum);
        results = airline.searchFlightsByNumber(fNum);

    } else if (choice == 2) {
        string orig, dest;
        cout << "Enter Origin: ";
        getline(cin, orig);
        cout << "Enter Destination: ";
        getline(cin, dest);
        results = airline.searchFlightsByRoute(orig, dest);

    } else if (choice == 3) {
        string date;
        cout << "Enter Date (YYYY-MM-DD): ";
        getline(cin, date);
        results = airline.searchFlightsByDate(date);

    } else {
        cout << "Invalid choice!" << endl;
        return;
    }

    if (results.empty()) {
        cout << "No flights found matching your search." << endl;
    } else {
        cout << "\nFound " << results.size() << " flight(s):" << endl;
        for (const auto& f : results) {
            f->displayDetails();
        }
    }
}

// Register a new passenger
void handleRegisterPassenger(Airline& airline) {
    cout << "\n--- Register Passenger ---" << endl;
    cout << "Select passenger class:" << endl;
    cout << "1. Economy" << endl;
    cout << "2. Business" << endl;
    cout << "3. First Class" << endl;
    cout << "Choice: ";

    int type;
    if (!safeReadInt(type)) return;

    string id, name, phone, email;
    cout << "Passenger ID: ";
    getline(cin, id);
    cout << "Full Name: ";
    getline(cin, name);
    cout << "Phone: ";
    getline(cin, phone);
    cout << "Email: ";
    getline(cin, email);

    if (type == 1) {
        airline.registerPassenger(make_shared<EconomyPassenger>(id, name, phone, email));
    } else if (type == 2) {
        airline.registerPassenger(make_shared<BusinessPassenger>(id, name, phone, email));
    } else if (type == 3) {
        airline.registerPassenger(make_shared<FirstClassPassenger>(id, name, phone, email));
    } else {
        cout << "Invalid passenger class!" << endl;
    }
}

// Remove a passenger
void handleRemovePassenger(Airline& airline) {
    cout << "\n--- Remove Passenger ---" << endl;
    string id;
    cout << "Enter Passenger ID: ";
    getline(cin, id);
    airline.removePassenger(id);
}

// View booking history
void handleViewHistory(Airline& airline) {
    cout << "\n--- Booking History ---" << endl;
    string id;
    cout << "Enter Passenger ID: ";
    getline(cin, id);
    airline.viewBookingHistory(id);
}

// Book a ticket
void handleBookTicket(Airline& airline) {
    cout << "\n--- Book a Ticket ---" << endl;
    string pID, fNum;
    cout << "Enter Passenger ID: ";
    getline(cin, pID);
    cout << "Enter Flight Number: ";
    getline(cin, fNum);

    try {
        airline.bookTicket(pID, fNum, getCurrentDate());
    } catch (const FlightFullException& e) {
        cout << "Booking Failed: " << e.what() << endl;
    } catch (const DuplicateBookingException& e) {
        cout << "Booking Failed: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Cancel a ticket
void handleCancelTicket(Airline& airline) {
    cout << "\n--- Cancel a Ticket ---" << endl;
    string ticketID, currentDate;
    cout << "Enter Ticket ID: ";
    getline(cin, ticketID);
    cout << "Enter Today's Date (YYYY-MM-DD): ";
    getline(cin, currentDate);

    try {
        airline.cancelTicket(ticketID, currentDate);
    } catch (const InvalidCancellationException& e) {
        cout << "Cancellation Failed: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Today's departures report
void handleTodaysDepartures(Airline& airline) {
    string today;
    cout << "Enter Today's Date (YYYY-MM-DD): ";
    getline(cin, today);
    airline.todaysDepartures(today);
}

// ==================== MAIN FUNCTION ====================
int main() {
    const string DATA_FILE = "skylink_data.txt";

    // Create airline instance
    Airline skylink("SkyLink Airways");

    // Try to load saved data
    skylink.loadFromFile(DATA_FILE);

    int choice = 0;

    // Main menu loop
    while (true) {
        displayMenu();
        if (!safeReadInt(choice)) {
            continue; // re-show menu on bad input
        }

        switch (choice) {
            case 1:
                handleAddFlight(skylink);
                break;
            case 2:
                handleRemoveFlight(skylink);
                break;
            case 3:
                handleSearchFlights(skylink);
                break;
            case 4:
                skylink.listAllFlights();
                break;
            case 5:
                handleRegisterPassenger(skylink);
                break;
            case 6:
                handleRemovePassenger(skylink);
                break;
            case 7:
                handleViewHistory(skylink);
                break;
            case 8:
                handleBookTicket(skylink);
                break;
            case 9:
                handleCancelTicket(skylink);
                break;
            case 10:
                handleTodaysDepartures(skylink);
                break;
            case 11:
                skylink.occupancyReport();
                break;
            case 12:
                skylink.topRevenueFlights();
                break;
            case 13:
                loadSampleData(skylink);
                break;
            case 14:
                skylink.saveToFile(DATA_FILE);
                cout << "\nThank you for using SkyLink Airways!" << endl;
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter 1-14." << endl;
        }
    }

    return 0;
}
