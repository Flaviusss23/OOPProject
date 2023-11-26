#pragma once
#include <string>
#include <iostream>

class Event {
protected:
    const int id = 0;
    std::string date = "";
    std::string time = "";
    char* name = nullptr;
    static int AVAILABLE_TICKETS;
    static int SOLD_TICKETS;

public:
    Event() : id(0) {
        this->name = new char[strlen("Unknown") + 1];
        strcpy(this->name, "Unknown");
    }

    Event(const int id, const char* name, std::string date, std::string time) : id(id) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->date = date;
        this->time = time;
    }

    int getId() const {
        return this->id;
    }

    std::string getName() const {
        return std::string(this->name);
    }

    std::string getDate() const {
        return std::string(this->date);
    }

    std::string getTime() const {
        return std::string(this->time);
    }

    int getAvailableTickets() const {
        return AVAILABLE_TICKETS;
    }

    int getSoldTickets() const {
        return SOLD_TICKETS;
    }

    ~Event() {
        if (this->name != nullptr)
            delete[] this->name;
    }

    void buyTicket(int noTickets);

    void returnTicket(int noTickets);

    bool operator!=(const Event& ev) const;

    friend std::ostream& operator<<(std::ostream& out, const Event& ev);
    friend std::istream& operator>>(std::istream& in, Event& ev);

private:
    static void markUnavailableSeats(int value);

    void setName(const char* name);
    void setDate(std::string date);
    void setTime(std::string time);
};

std::ostream& operator<<(std::ostream& out, const Event& ev);
std::istream& operator>>(std::istream& in, Event& ev);

int Event::AVAILABLE_TICKETS = 300;
int Event::SOLD_TICKETS = 0;
