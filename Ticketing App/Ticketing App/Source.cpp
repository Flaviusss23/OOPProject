#include <iostream>
#include <string>
#include "Ticket.h"
#include "Event.h"
#include "Location.h"

using namespace std;

int main() {
    int option;
    do {
        cout << "Welcome to the ticketing app! Choose an option by typing the corresponding number:\n";
        cout << "1. Buy tickets\n";
        cout << "2. Return tickets\n";
        cout << "3. Show available events\n";
        cout << "4. Admin mode\n";
        cout << "5. Quit application\n";

        cin >> option;

        switch (option) {
        case 1:
            // Buy tickets functionality
            break;
        case 2:
            // Return tickets functionality
            break;
        case 3:
            // Show available events functionality
            break;
        case 4:
            // Admin mode functionality
            break;
        case 5:
            cout << "Thank you for checking out the app!\n";
            return 0;
        default:
            cout << "Wrong input.\n";
        }
    } while (option != 5);

    return 0;
}
