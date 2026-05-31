# Makefile for SkyLink Airways - Airline Reservation & Flight Management System
# Compiler: g++ with C++17 standard

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I include

# Source files
SRC = src/main.cpp \
      src/Flight.cpp \
      src/DomesticFlight.cpp \
      src/InternationalFlight.cpp \
      src/CharterFlight.cpp \
      src/Passenger.cpp \
      src/EconomyPassenger.cpp \
      src/BusinessPassenger.cpp \
      src/FirstClassPassenger.cpp \
      src/Ticket.cpp \
      src/Airline.cpp

# Output executable
TARGET = airline_system

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean build files
clean:
	del /Q $(TARGET).exe 2>nul

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
