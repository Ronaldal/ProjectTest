#include<iostream>
#include <string.h>
#ifndef __STATUS_H
#define __STATUS_H
#pragma warning (disable: 4996)
#include <ctime>
//The status class is for using the statuses in the program. 
//The text string is for the status and the dateTime string is for saving the time the status written.
class Status
{
private:
	char* text;
	char* dateTime;
public:
	Status(const char* text);
	void showStatus() const;
	~Status();
};

#endif // !__STATUS_H
