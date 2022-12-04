#include "MenuFunctions.h"
#include "System.h"
using namespace std;

//for cin.getline
void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}
void printMenu()
{
	cout << "\n--------MENU--------\nPlease pick your option:" << endl;
	cout << "1- Add a friend" << endl;
	cout << "2- Add fan page" << endl;
	cout << "3- Add a status to a friend / fan page." << endl;
	cout << "4- View all statuses of a member / fan page." << endl;
	cout << "5- View the 10 most recent statuses of his friends." << endl;
	cout << "6- A friendship link between two friends." << endl;
	cout << "7- Unfriending between two friends " << endl;
	cout << "8- Add a member to fan page " << endl;
	cout << "9- Remove a member from the fan page" << endl;
	cout << "10- Show all entities registered to the system" << endl;
	cout << "11- Show all the friends of a certain friend / the fans of a certain fan page" << endl;
	cout << "12- Exit." << endl;
}
//the main function that runs the system, using switch case for every member or fan page choose.
void Running(int memberChoose, System& system)
{
	if (memberChoose != 12 && memberChoose !=10)
	{
		char name[SIZE];
		strcpy(name, getName());
		switch (memberChoose)
		{
		case 1:
			addMemberToSystem(system, name);
			break;
		case 2:
			addFanPageToSystem(system, name);
			break;
		case 3:
			addStatusToMemberOrFanPage(system, name);
			break;
		case 4:
			viewAllStatusesOfMemberOrFanPage(system, name);
			break;
		case 5:
			viewLast10Statuses(system, name);
			break;
		case 6:
			friendShipLinkBetweenTwoMembers(system, name);
			break;
		case 7:
			unfriendingBetweenTwoMembers(system, name);
			break;
		case 8:
			addMemberToFanPage(system, name);
			break;
		case 9:
			deleteMemberFromFanPage(system, name);
			break;
		case 11:
			showAllFriendsOfMemberOrFanPage(system, name);
			break;
		}
	}
	else
	{
		if (memberChoose==10)
			showAllEntitiesRegisteredToSystem(system);
		else
			cout << "Goodbye." << endl;
	}
}
char* getName()
{
	cout << "Please enter your name:" << endl;
	char name[SIZE];
	cleanBuffer();
	cin.getline(name, SIZE);
	return name;
}
//adding member to system
void addMemberToSystem(System& system, const char* name)
{

	cout << "Please enter your date of birth(day  month  year)" << endl;
	int day, month, year;
	cin >> day >> month >> year;

	Date d(day, month, year);

	if (system.addMember(d, name))
		cout << "The member added successfully" << endl;
	else
		cout << "The member already exist" << endl;
}

void addFanPageToSystem(System& system, const char* name)
{
	if (system.addFanPage(name))
		cout << "The fan page added successfully" << endl;
	else
		cout << "The fan page already exist" << endl;
}

void addStatusToMemberOrFanPage(System& system, const char* name)
{
	char choose;
	cout << "Please Pick your type (M=member or F=fan page): " << endl;
	cin >> choose;
	if (choose == MEMBER)
	{
		if (system.isMemberAlreadyExist(name) == NOT_FOUND)
		{ 
			cout << "The member doesn't exist!" << endl;
			return;
		}

		char statusToAdd[SIZE];
		cout << "Please enter status : " << endl;
		cleanBuffer();
		cin.getline(statusToAdd, SIZE);
		Status* s1 = new Status(statusToAdd);
		system.addStatus(name, s1);
	}
	else
	{
		if (system.isFanPageAlreadyExist(name) == NOT_FOUND)
		{
			cout << "The fan page doesn't exist!" << endl;
			return;
		}
		char statusToAdd[SIZE];
		cout << "Please enter status : " << endl;
		cleanBuffer();
		cin.getline(statusToAdd, SIZE);
		Status* s1 = new Status(statusToAdd);
		system.addStatusToFanPage(name, s1);
	}
	cout << "The status added succesfully" << endl;
}

void viewAllStatusesOfMemberOrFanPage(System& system, const char* name)
{
	char choose;
	cout << "Please Pick your type (M=member / F=fan page): " << endl;
	cin >> choose;
	if (choose == MEMBER)
		system.showStatusesOfMember(name);
	else
		system.showStatusesOfFanPage(name);

}
void viewLast10Statuses(System& system ,const char* name)
{
	system.showLast10Statuses(name);
}


void friendShipLinkBetweenTwoMembers(System& system ,const char* name)
{
	char nameOfMemberToAdd[SIZE];

	int placeOfFirstMember = system.isMemberAlreadyExist(name);//check if the member already exist and if so get his index.
	if (placeOfFirstMember != NOT_FOUND)
	{
		cout << "Please enter the name of the member you want to add as a friend" << endl;
		cin.getline(nameOfMemberToAdd, SIZE);

		int placeOfMemberToAdd = system.isMemberAlreadyExist(nameOfMemberToAdd);
		if (placeOfMemberToAdd != NOT_FOUND)
		{
			if (system.friendShipLinkBetweenTwoMembers(placeOfFirstMember, placeOfMemberToAdd))
				cout << "The friend succesfully added" << endl;

			else
				cout << " The members are already friends" << endl;
		}
		else
			cout << "The member doesn't exist!" << endl;
	}
	else
		cout << "The member doesn't exist!" << endl;
}
void unfriendingBetweenTwoMembers(System& system, const char* name)
{
	char nameOfMemberToRemove[SIZE];

	int placeOfFirstMember = system.isMemberAlreadyExist(name);//same like adding friend
	if (placeOfFirstMember != NOT_FOUND)
	{
		cout << "Please enter the name of the member you want to remove from your friends" << endl;
		cin.getline(nameOfMemberToRemove, SIZE);

		int placeOfMemberToRemove = system.isMemberAlreadyExist(nameOfMemberToRemove);
		if (placeOfMemberToRemove != NOT_FOUND)
		{
			if (system.deleteFriendShipBetweenTwoMembers(placeOfFirstMember, placeOfMemberToRemove))
				cout << "The friend succesfully removed" << endl;

			else
				cout << " The members are already not friends" << endl;
		}
		else
			cout << "The member doesn't exist!" << endl;
	}
	else
		cout << "The member doesn't exist!" << endl;
}
//add member to fan page.
void addMemberToFanPage(System& system, const char* nameOfFanPage)
{

	int placeOfFanFage = system.isFanPageAlreadyExist(nameOfFanPage);
	if (placeOfFanFage != NOT_FOUND)
	{
		char nameOfMemberToAdd[SIZE];
		cout << "Please enter the name of the member you want to add" << endl;
		cin.getline(nameOfMemberToAdd, SIZE);

		int placeOfMemberToAdd = system.isMemberAlreadyExist(nameOfMemberToAdd);

		if (placeOfMemberToAdd != NOT_FOUND)
		{
			if (system.addMemberToFanPage(placeOfFanFage, placeOfMemberToAdd))
				cout << "The member succesfully added" << endl;
			else
				cout << " The member is already following the fan page" << endl;

		}
		else
			cout << "The member doesn't exist!" << endl;
	}
	else
		cout << "The fan page doesn't exist!" << endl;

}
void deleteMemberFromFanPage(System& system, const char* nameOfFanPage)
{
	int placeOfFanFage = system.isFanPageAlreadyExist(nameOfFanPage);
	if (placeOfFanFage != NOT_FOUND)
	{
		char nameOfMemberToRemove[SIZE];
		cout << "Please enter the name of the member you want to delete" << endl;
		cin.getline(nameOfMemberToRemove, SIZE);

		int placeOfMemberToRemove = system.isMemberAlreadyExist(nameOfMemberToRemove);

		if (placeOfMemberToRemove != NOT_FOUND)
		{
			if (system.deleteMemberFromFanPage(placeOfFanFage, placeOfMemberToRemove))
				cout << "The member removed succesfully" << endl;
			else
				cout << " The member is not following the fan page" << endl;

		}
		else
			cout << "The member doesn't exist!" << endl;
	}
	else
		cout << "The fan page doesn't exist!" << endl;
}
void showAllEntitiesRegisteredToSystem(System& system)
{
	cout << "The members that are registered to the system are:" << endl;
	system.showMembers();
	cout << "The fan pages that are registered to the system are:" << endl;
	system.showFanPages();
}
void showAllFriendsOfMemberOrFanPage(System& system, const char* name)
{
	char choose;
	cout << "Please Pick your type (M=member or F=fan page): " << endl;
	cin >> choose;
	if (choose == MEMBER)
		system.showAllFriendsOfMember(name);
	else
		system.showAllFollowersOfFanPage(name);
}