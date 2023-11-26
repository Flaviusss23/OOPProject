#pragma once
#include <string>

class Location {
protected:
    char* name = nullptr;
    int noOfRows = 0;
    int noOfZones = 0;
    int* noOfSeatsPerRow = nullptr;

    const static int MIN_SEATS_PER_ROW = 1;
    const static int MAX_SEATS_PER_ROW = 25;

    void validateName(const char* name) {
        if (strlen(name) > 49)
            throw std::invalid_argument("Name exceeds 50 characters.");
    }

    void validateRows(int value) {
        if (value <= 0)
            throw std::invalid_argument("Rows must be greater than 0.");
    }

    void validateZones(int value) {
        if (value <= 0)
            throw std::invalid_argument("Zones must be greater than 0.");
    }

    void validateSeatsPerRow(int* seatsPerRow, int rows) {
        for (int i = 0; i < rows; ++i) {
            if (seatsPerRow[i] < MIN_SEATS_PER_ROW || seatsPerRow[i] > MAX_SEATS_PER_ROW)
                throw std::invalid_argument("Number of seats per row must be between 1 and 25.");
        }
    }

public:
    // Getters
    std::string getName() {
        return std::string(this->name);
    }

    int getRows() {
        return this->noOfRows;
    }

    int getZones() {
        return this->noOfZones;
    }

    int* getNoOfSeatsPerRow() {
        return this->noOfSeatsPerRow;
    }

    // Setters
    void setName(const char* name) {
        validateName(name);
        if (this->name != nullptr)
            delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setRows(int value) {
        validateRows(value);
        this->noOfRows = value;
    }

    void setZones(int value) {
        validateZones(value);
        this->noOfZones = value;
    }

    void setNoOfSeatsPerRow(int* newSeatsPerRow) {
        validateSeatsPerRow(newSeatsPerRow, this->noOfRows);
        if (this->noOfSeatsPerRow != nullptr)
            delete[] this->noOfSeatsPerRow;
        this->noOfSeatsPerRow = new int[this->noOfRows];
        for (int i = 0; i < this->noOfRows; ++i)
            this->noOfSeatsPerRow[i] = newSeatsPerRow[i];
    }


    Location(const Location& loc) { //copy ctor
        std::cout << "\nCopy constructor called";
        this->setName(loc.name);
        this->setRows(loc.noOfRows);
        this->setZones(loc.noOfZones);
        this->setNoOfSeatsPerRow(loc.noOfSeatsPerRow);
    }

    ~Location() { //destructor
        std::cout << "\nDestructor for location called";
        if (this->name != nullptr)
            delete[] this->name;
        if (this->noOfSeatsPerRow != nullptr)
            delete[] this->noOfSeatsPerRow;
    }

    int getTotalNoOfSeats() {
        int totalSeats = 0;
        for (int i = 0; i < noOfZones; i++)
            for (int j = 0; j < noOfRows; j++)
                totalSeats += noOfSeatsPerRow[j];
        return totalSeats;
    }

    Location& operator= (const Location& loc) { //overload for = operator
        if (this != &loc) {
            this->setName(loc.name);
            this->setRows(loc.noOfRows);
            this->setNoOfSeatsPerRow(loc.noOfSeatsPerRow);
            this->setZones(loc.noOfZones);
        }
        return *this;
    }

    bool operator>(Location& loc) {
        if (this->getTotalNoOfSeats() > loc.getTotalNoOfSeats())
            return true;
        else
            return false;
    }

    bool operator<(Location& loc) {
        if (this->getTotalNoOfSeats() < loc.getTotalNoOfSeats())
            return true;
        else
            return false;
    }

    bool operator>=(Location& loc) {
        if (this->getTotalNoOfSeats() >= loc.getTotalNoOfSeats())
            return true;
        else
            return false;
    }

    bool operator<=(Location& loc) {
        if (this->getTotalNoOfSeats() <= loc.getTotalNoOfSeats())
            return true;
        else
            return false;
    }

    bool operator==(Location& loc) {
        if (this->getTotalNoOfSeats() == loc.getTotalNoOfSeats())
            return true;
        else
            return false;
    }
};