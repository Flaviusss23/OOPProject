#pragma once
#include <cstring>
#include <iostream>

enum Sections { LAWN, TRIBUNE, VIP, PRESS };

class Ticket {
private:
    char* nameOfEvent = nullptr;
    int price = 50;
    int seat = 0;
    int row = 0;
    Sections section = LAWN;
    std::string date = "";
    std::string time = "";
    const std::string ID;

public:

    Ticket() { 
        this->nameOfEvent = new char[strlen("Unknown") + 1];
        strcpy(this->nameOfEvent, "Unknown");
        this->price = 50;
        this->seat = 0;
        this->row = 0;
        this->section = LAWN;
        this->time = "";
        this->date = "";
    }

    Ticket(int price, int seat, int row, Sections section, std::string date, std::string time, std::string ID)
        : ID(ID) {
        this->price = price;
        this->seat = seat;
        this->row = row;
        this->section = section;
        this->date = date;
        this->time = time;
    }

    std::string getNameOfEvent() {
        return std::string(this->nameOfEvent);
    }
    void setNameOfEvent(const char* eventName) {
        if (this->nameOfEvent != nullptr)
            delete[] this->nameOfEvent;
        this->nameOfEvent = new char[strlen(eventName) + 1];
        strcpy(this->nameOfEvent, eventName);
    }

    int getPrice() {
        return this->price;
    }
    void setPrice(int ticketPrice) {
        this->price = ticketPrice;
    }

    int getSeat() {
        return this->seat;
    }
    void setSeat(int seatNumber) {
        this->seat = seatNumber;
    }

    int getRow() {
        return this->row;
    }
    void setRow(int rowNumber) {
        this->row = rowNumber;
    }

    std::string getSection() {
        std::string sectionNames[] = { "LAWN", "TRIBUNE", "VIP", "PRESS" };
        return sectionNames[this->section];
    }
    void setSection(Sections ticketSection) {
        this->section = ticketSection;
    }

    std::string getDate() {
        return std::string(this->date);
    }
    void setDate(std::string ticketDate) {
        this->date = ticketDate;
    }

    std::string getTime() {
        return std::string(this->time);
    }
    void setTime(std::string ticketTime) {
        this->time = ticketTime;
    }

    std::string getID() {
        return std::string(this->ID);
    }

    float priceCalculator(int noOfTickets, std::string section) {
        float totalPrice = 0.0;

        if (section == "LAWN")
            totalPrice = static_cast<float>(noOfTickets * price);
        else if (section == "TRIBUNE")
            totalPrice = static_cast<float>(noOfTickets * price * 1.5);
        else if (section == "VIP")
            totalPrice = static_cast<float>(noOfTickets * price * 3);
        else if (section == "PRESS")
            totalPrice = 0;  // Press section tickets are free

        return totalPrice;
    }

    ~Ticket() {
        if (this->nameOfEvent != nullptr)
            delete[] this->nameOfEvent;
    }

    Ticket& operator=(const Ticket& tick) {
        if (this != &tick) {
            this->price = tick.price;
            this->seat = tick.seat;
            this->row = tick.row;
            this->section = tick.section;
            this->date = tick.date;
            this->time = tick.time;
            if (this->nameOfEvent != nullptr)
                delete[] this->nameOfEvent;
            if (tick.nameOfEvent != nullptr) {
                this->nameOfEvent = new char[strlen(tick.nameOfEvent) + 1];
                strcpy(this->nameOfEvent, tick.nameOfEvent);
            }
            else {
                this->nameOfEvent = nullptr;
            }
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, Ticket& tick) {
        out << "Name of Event: " << tick.getNameOfEvent() << std::endl;
        out << "Price: " << tick.getPrice() << std::endl;
        out << "Seat: " << tick.getSeat() << std::endl;
        out << "Row: " << tick.getRow() << std::endl;
        out << "Section: " << tick.getSection() << std::endl;
        out << "Date: " << tick.getDate() << std::endl;
        out << "Time: " << tick.getTime() << std::endl;
        out << "ID: " << tick.getID() << std::endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Ticket& tick) {

        std::cout << "Enter name of Event: ";
        char tempName[100];
        in >> tempName;
        tick.setNameOfEvent(tempName);

        std::cout << "Enter price: ";
        int tempPrice;
        in >> tempPrice;
        tick.setPrice(tempPrice);

        std::cout << "Enter seat: ";
        int tempSeat;
        in >> tempSeat;
        tick.setSeat(tempSeat);

        std::cout << "Enter row: ";
        int tempRow;
        in >> tempRow;
        tick.setRow(tempRow);


        return in;
    }
};
