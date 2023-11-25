#pragma once
#include <string>
#include <iostream>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

class Location {
protected:
	char* name = nullptr; // name of the stadium
	int noOfRows = 0;
	int noOfZones = 0;
	int* noOfSeatsPerRow = nullptr;

	const static int MIN_SEATS_PER_ROW = 1;
	const static int MAX_SEATS_PER_ROW = 30;

	Location() //default ctor
	{
		std::cout << "\nCalling default constructor for location";
		this->name = new char[strlen("Unknown") + 1];
		strcpy(this->name, "Unknown");
	}

	Location(const char* name, int noOfRows, int noOfZones, int* noOfSeatsPerRow) { //ctor with param
		this->setName(name);
		this->setRows(noOfRows);
		this->setZones(noOfZones);
		this->setNoOfSeatsPerRow(noOfSeatsPerRow, noOfRows);
	}

public:

	std::string getName() { //getter for name as string
		return std::string(this->name);
	}

	char* getNameAsPointer() { //getter for name as pointer
		char* nameCopy = new char[strlen(this->name) + 1];
		strcpy_s(nameCopy, strlen(this->name) + 1, this->name);
		return nameCopy;
	}

	void setName(const char* name) { //setter for name
		//validating the input
		if (strlen(name) > 49)
			throw std::exception("Name over 50 characters");
		if (this->name != nullptr)
			delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	int getRows() {
		return this->noOfRows;
	}

	void setRows(int value) {
		if (value > 0)
			this->noOfRows = value;
		else
			throw std::exception("Value of rows can not be negative or null");
	}
	int getZones() {
		return this->noOfZones;
	}

	void setZones(int value) {
		if (value > 0)
			this->noOfZones = value;
		else
			throw std::exception("Value of zones can not be negative or null");
	}
	void setNoOfSeatsPerRow(int* newSeatsPerRow, int newRows) {
		if (newSeatsPerRow == nullptr) throw std::exception("The newSeatsPerRow pointer is null");
		if (newRows <= 0) throw std::exception("The newRows value can not be negative or null");
		for (int i = 0; i < noOfRows; i++) {
			if (newSeatsPerRow[i] < MIN_SEATS_PER_ROW || newSeatsPerRow[i] > MAX_SEATS_PER_ROW) {
				throw std::exception("One of the rows from the new array has a number of seats per row that is not in the specified interval of (1,30)");
			}
			if (this->noOfSeatsPerRow != nullptr)
				delete[] this->noOfSeatsPerRow;
			this->noOfSeatsPerRow = new int[newRows];
			for (int j = 0; j < newRows; j++) {
				this->noOfSeatsPerRow[i] = newSeatsPerRow[i];
			}
			this->noOfRows = newRows;
		}
	}

	Location(const Location& loc) { //copy ctor
		std::cout << "\nCopy constructor called";
		this->setName(loc.name);
		this->setRows(loc.noOfRows);
		this->setZones(loc.noOfZones);
		this->setNoOfSeatsPerRow(loc.noOfSeatsPerRow, loc.noOfRows);
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
			this->setNoOfSeatsPerRow(loc.noOfSeatsPerRow, loc.noOfRows);
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