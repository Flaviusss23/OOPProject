#pragma once
#include <string>
#include <iostream>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

class Event {
protected:
	const int id = 0;
	std::string date = ""; //date format DD-MM-Y
	std::string time = ""; //time format 15:47
	char* name = nullptr;

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

	int getId() {
		return this->id;
	}

	std::string getName() { //getter for name as string
		return std::string(this->name);
	}

	std::string getDate() { //getter for date as string
		return std::string(this->date);
	}

	std::string getTime() { //getter for time as string
		return std::string(this->time);
	}

	~Event() { //destructor
		if (this->name != nullptr)
			delete[] this->name;
	}

	Event(const Event& e) : id(e.id) { //copy ctor
		if (this->name != nullptr)
			delete[] this->name;
		this->name = new char[strlen(e.name) + 1];
		strcpy(this->name, e.name);
		this->date = e.date;
		this->time = e.date;
	}

	Event& operator=(const Event& e) { //overload for = operator
		if (this != &e) {
			if (this->name != nullptr)
				delete[] this->name;
			this->name = new char[strlen(e.name) + 1];
			strcpy(this->name, e.name);
		}
		this->date = e.date;
		this->time = e.date;
		
	}
};