#include <iostream>
#include<conio.h>
#include "Date.h"
using namespace std;

int main() {
    Date d1, d2;
    int choice;
    cout << "Enter the date to display and perform operations on it" << endl;
    cin >> d1;
    do {
        cout << "\n";
        cout << "**************************\n";
        cout << "*        Main Menu       *\n";
        cout << "**************************\n";
        cout << "*  1. Display date       *\n";
        cout << "*  2. Increase date by 1 *\n";
        cout << "*  3. Decrease date by 1 *\n";
        cout << "*  4. Subtract dates     *\n";
        cout << "*  5. Exit               *\n";
        cout << "**************************\n";
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            cout << "Current date:\n " << d1 << endl;
            break;
        case 2:
            d1++;
            cout << "Date increased by 1: " << endl << d1 << endl;
            break;
        case 3:
            d1--;
            cout << "Date decreased by 1: \n" << d1 << endl;
            break;
        case 4:{
            cout << "Enter the date you want to subtract: "<<endl;
            cin >> d2;
            d1.checksubtractDate(d2);
            int daysDiff = d1 - d2;
            
                cout << "Number of days between "<<d1.getDate()<<"/"<<d1.getMonth()<<"/"<<d1.getYear()<<" and " << d2.getDate() << "/" << d2.getMonth() << "/" << d2.getYear()<<" are : " << daysDiff << endl;
            }
            break;
        case 5:
            cout << "Exiting the program\n";
            exit(0);
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (true);

		return 0;
}