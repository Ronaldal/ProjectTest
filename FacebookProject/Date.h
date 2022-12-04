#include <iostream>

#ifndef __DATE_H
#define __DATE_H
/*
This class to save the date of birth of member
*/
class Date
{
private:
	int day, month, year;
public:
	Date (const int day  , const int month, const int year): day(day), month(month), year(year)
	{
	}
	void showDate() const
	{
		std::cout << day << "/" << month << "/" << year;
	}
};

#endif // !__DATE_H
