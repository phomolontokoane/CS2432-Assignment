#include <iostream>
#include "headers/System.h"
#include "headers/Floor.h"
#include "headers/Record.h"

using namespace std;

void InventorySystem(System&);
void RecordSystem(System&);

int main(int argc, char const *argv[])
{
    System system;
    system.loadData();

    int choice;
    cout << "==========================Library system==================================" << "\n\n";

    do
    {
        cout << "0. Stop Program" << endl;
        cout << "1. Enter Inventory System" << endl;
        cout << "2. Enter Records System" << endl
             << endl;
        
        cout << "Enter choice(0-2): ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << endl
                 << "Terminating programm" << endl;
            break;
        case 1:
            InventorySystem(system);
            break;
        case 2:
            RecordSystem(system);
            break;
        default:
            cout << "Error: please pick a choice between 0 and 2" << endl
                 << endl;
            break;
        }
    } while (choice != 0);

    system.saveData(); // save data
    cout << "===========================================================================" << "\n\n";
    return 0;
}

void InventorySystem(System& system) {
    cout << "=============================Floor system==================================" << "\n\n";
    
    int choice;
    do
    {
        cout << "0. Exit Floor Sytstem" << '\n';
        cout << "1. Display Floors" << '\n';
        cout << "2. Display Shelves" << '\n';
        cout << "3. Display Books in a shelf" << '\n';
        cout << "4. Create Floor" << '\n';
        cout << "5. Create shelf" << '\n';
        cout << "6. Create book" << "\n\n";

        cout << "Enter choice: ";
        cin >> choice;

        cout << "\n";
        switch (choice)
        {
        case 0:
            break;
        case 1:
            system.displayFloors();
            break;
        case 2:
            system.displayShelves();
            break;
        case 3:
            system.displayBooks();
            break;
        case 4:
            system.createFloor();
            break;
        case 5:
            system.createShelf();
            break;
        case 6:
            system.createBook();
            break;
        default:
            cout << "Error: please enter integer between 0 and 6"<< '\n';
            break;
        }
        cout << "\n";
    } while (choice != 0);  
}

void RecordSystem(System& system) {
    cout << "=============================Record system=================================" << "\n\n";

    int choice;
    do
    {
        cout << "0. Exit Record System" << '\n';
        cout << "1. Display All Records" << '\n';
        cout << "2. Display Borrowed Books" << '\n';
        cout << "3. Display Returned Books" << '\n';
        cout << "4. Handle Book Return" << "\n";
        cout << "5. Add Record" << "\n\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            system.displayRecords();
            break;
        case 2:
            system.displayBorrowedBooks();
            break;
        case 3:
            system.displayReturnedBooks();
            break;
        case 4:
            system.handleReturnBook();
            break;
        case 5:
            system.addRecord();
            break;
        default:
            cout << "Error: please enter an integer between 0 and 4" << '\n';
            break;
        }
        cout << "\n";
    } while (choice != 0);
}