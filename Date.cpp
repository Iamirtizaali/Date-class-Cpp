#include "Date.h"
#include <iostream>
using namespace std;
//here is the implementation of Date class code functions
//this is static array to store number of total days in a month 
int Date::TotalDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//this static array holds names of all the months 
string Date::MonthName[12] = { "January","Feburary","March","April", "May", "June", "July", "August", "September", "October", "November","December" };
//Default constructor
Date::Date() {
	day = 1;
	month = 1;
	year = 1;
}
//constructor which takes date and set default values for month and year 
Date::Date(int d) {
	day = d;
	month = 1;
	year = 1;
}
//constructor which takes date and month as parameter and set default value for year
Date::Date(int d, int m) {
	day = d;
	month = m;
	year = 1;
}
//constructor which takes date , month and year as parameters and assign them to member variables
Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

//Mutators or Setters
void Date::setDate(int d) {
	day = d;
}
void Date::setMonth(int m) {
	month = m;
}
void Date::setYear(int y) {
	year = y;
}

//Getter functions
int Date::getDate() {
	return day;
}
int Date::getMonth() {
	return month;
}
int Date::getYear() {
	return year;
}


//Validation functions
void Date::dateValidation(int& date) {
	while (date<1 || date>TotalDays[month - 1])
	{
		cout << "Sorry you are enterting wrong date." << endl;
		cout << "Enter the date again: ";
		cin >> date;
	}
}
void Date::monthValidation(int& month) {
	while (month < 1 || month>12)
	{
		cout << "Sorry you are entering the wrong month." << endl;
		cout << "Enter the month again: ";
		cin >> month;
	}
}
void Date::yearValidation(int& year) {
	while (year < 0)
	{
		cout << "Sorry you are entering wrong digit for year." << endl;
		cout << "Enter the year again: ";
		cin >> year;
	}
}
bool Date::leapYearValidation(int year) {
	bool leap = false;
	if (year % 400 == 0) {
		leap = true;
	}
	// Not a leap year if divisible by 100 but not divisible by 400
	else if (year % 100 == 0) {
		leap = false;
	}
	// Leap year if not divisible by 100 but divisible by 4
	else if (year % 4 == 0) {
		leap = true;
	}
	// All other years are not leap years
	else {
		leap = false;
	}
	return leap;
}
void Date::checksubtractDate(Date& d) {
	while (true)
	{
		if (d.year > this->year) {
			cout << "You are entering wrong value for year" << endl;
			cout << "Enter the correct year: ";
			cin >> d.year;
			continue;
		}
		else if (d.year==this->year)
		{
			if (d.month > this->month) {
				cout << "Sorry you are entering wrong value of month" << endl;
				cout << "Enter the month again: ";
				cin >> d.month;
				continue;
			}
			else if (d.month==this->month)
			{
				if (d.day > this->day) {
					cout << "Sorry you are entering wrong date" << endl;
					cout << "Enter the correct value of date: ";
					cin >> d.day;
					continue;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
}

//simplify date function which checks for last and first day of month and year and updates accordingly
void Date::simpilifyDate() {
	if (leapYearValidation(this->year))
	{
		TotalDays[1] = 29;
	}
	if (day == 0)
	{
		month--;
		if (month == 0)
		{
			month = 12;
			year--;
		}
		day = TotalDays[month - 1];
	}
	else if (day == (TotalDays[month - 1] + 1))
	{
		month++;
		if (month == 13)
		{
			year++;
			month = 1;
		}
		day = 1;
	}
}

//Operators overloading
//subtraction operator overloading which subtracts two dates and returns number of days between them
int Date::operator-(const Date& right) {
	simpilifyDate();
	int tdays = 0;
	Date temp = *this;
	if (this->month == right.month && this->year == right.year)
	{
		tdays += this->day - right.day;
		return tdays;
	}
	tdays += temp.day;
	/*if (leapYearValidation(right.year))
	{
		TotalDays[1] = 29;
	}
	else
	{
		TotalDays[1] = 28;
	}*/
	tdays += (right.TotalDays[right.month - 1] - right.day);
	temp.month--; 
	while (!(temp.year == right.year && temp.month == right.month))
	{
		tdays += TotalDays[temp.month - 1];
		temp.month--;
		if (temp.month == 0)
		{
			temp.month = 12;
			if (leapYearValidation(temp.year))
			{
				tdays++;
			}
			else
			{
				TotalDays[1] = 28;
			}
			temp.year--;
		}
	}
	if (right.month > 2 && this->year>right.year)
	{
		tdays--;
	}
	return tdays;
}

//prefix increment operator
Date& Date::operator++() {
	this->day++;
	this->simpilifyDate();
	return *this;
} 
//postfix increment operator
Date Date::operator++(int) {
	Date temp = *this;
	this->day++;
	this->simpilifyDate();
	return temp;

} 
//prefix decrement operator
Date& Date::operator--() {
	this->day--;
	this->simpilifyDate();
	return *this;
}
//postfix decrement operator
Date Date::operator--(int) {
	Date temp = *this;
	this->day--;
	this->simpilifyDate();
	return temp;
} 
//friends functions for cin and cout as operator overloading
ostream& operator<<(ostream& COUT, const  Date& n) {
	COUT << "-----------------------------------------" << endl;
	COUT << Date::MonthName[n.month - 1] << " " << n.day << ", " << n.year << endl;
	COUT << n.day << " " << Date::MonthName[n.month - 1] << " " << n.year << endl;
	COUT << "-----------------------------------------" << endl;
	return COUT;
}
istream& operator>>(istream& CIN, Date& m) {
	cout << "Enter the month(1-12): ";
	CIN >> m.month;
	m.monthValidation(m.month);
	cout << "Enter the Date: ";
	CIN >> m.day;
	m.dateValidation(m.day);
	cout << "Enter the year: ";
	CIN >> m.year;
	m.yearValidation(m.year);
	return CIN;
	m.simpilifyDate();
}