#include "Status.h"
using namespace std;

//c'tor for status
Status::Status(const char* text1)
{
	// current date and time on the current system
	time_t now = time(0);
	char* sTime = ctime(&now);
	dateTime = new char[strlen(sTime) + 1];
	strcpy(dateTime, sTime);
	text = new char[strlen(text1) + 1];
	strcpy(text, text1);
}
void Status::showStatus() const
{
	cout << "The status is: " << text << " || wrote at: " << dateTime << endl;
}
//d'tor for status
Status::~Status()
{
	delete dateTime;
	delete text;
}