#include <iostream>
#include <string>
using namespace std;

#pragma once

class Date {
private:
    int day;
    int month;
    int year;
    static int TotalDays[12];  // Array to store total days in each month
    static string MonthName[12];  // Array to store names of months

public:
    // Constructors
    Date();  // Default constructor
    Date(int);  // Constructor with day parameter
    Date(int, int);  // Constructor with day and month parameters
    Date(int, int, int);  // Constructor with day, month, and year parameters

    // Setter methods
    void setDate(int);
    void setMonth(int);
    void setYear(int);

    // Getter methods
    int getDate();
    int getMonth();
    int getYear();

    // Validation methods
    void dateValidation(int&);
    void monthValidation(int&);
    void yearValidation(int&);
    bool leapYearValidation(int);
    // Utility methods
    void simpilifyDate();  // Simplify date by adjusting day, month, and year
    void checksubtractDate(Date&);  // Check and validate date subtraction

    // Operator overloading
    int operator-(const Date&);  // Subtract two dates to get the number of days between them
    Date& operator++();  // Prefix increment operator
    Date operator++(int);  // Postfix increment operator
    Date& operator--();  // Prefix decrement operator
    Date operator--(int);  // Postfix decrement operator

    // Friend functions for input and output
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
};
