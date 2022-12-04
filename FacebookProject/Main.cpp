
#include "MenuFunctions.h"
using namespace std;

void main()
{
	//Date d1(23, 06, 98);
	//Date d2(14, 04, 97);
	//s.addMember( d1, "Shafir");
	//s.addMember(d2, "Ohad");
	//s.addMember(d1, "Ronald");
	//s.addMember(d1, "Efron");
	//s.addFanPage("Macabbi Haifa");
	//s.addFanPage("Daniel Ponkatz the king");
	//s.addFanPage("MTA");
	System s;
	int choose;

	do {
		printMenu();
		cin >> choose;
		Running(choose, s);
	} while (choose != 12);
	
}
