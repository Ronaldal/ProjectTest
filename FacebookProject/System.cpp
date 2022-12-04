#include "System.h"
using namespace std;

//constractor 
//here we allocate all the entities arrays.
System::System()
{
	allMembersArrLogSize = 0;
	allMembersArrPhySize = 1;

	allMembersArr = new Member * [allMembersArrPhySize];

	allFanPagesArrLogSize = 0;
	allFanPagesArrPhySize = 1;

	allFanPagesArr = new fanPage * [allFanPagesArrPhySize];

}

//in this function we add a member to the the all members array using the logical physical algorithem.
//return true if the add success.
bool System::addMember(const Date& birthDate, const char* name)
{
	
	if (isMemberAlreadyExist(name) == NOT_FOUND)
	{
		Member* m = new Member(name, birthDate);
		if (allMembersArrLogSize == allMembersArrPhySize)
		{
			allMembersArrPhySize *= 2;
			allMembersArr = (Member**)reallocation(allMembersArr, allMembersArrPhySize, sizeof(Member*));
		}
		allMembersArr[allMembersArrLogSize++] = m;
		return true;
	}
	return false;
}

//this function check if the fan page already exist in the system.
//if so, returns the index of the fan page in the array, otherwise returns false.
int System::isFanPageAlreadyExist(const char* name) const
{
	for (int i = 0; i < allFanPagesArrLogSize; i++)
	{
		if (strcmp(name, allFanPagesArr[i]->getFanPageName()) == 0)
			return i;
	}
	return NOT_FOUND;
}
//this function check if the member already exist in the system.
//if so, returns the index of the member in the array, otherwise returns false.
int System::isMemberAlreadyExist(const char* name) const
{
	for (int i = 0; i < allMembersArrLogSize; i++)
	{
		if (strcmp(name, allMembersArr[i]->getMemberName()) == 0)
			return i;
	}
	return NOT_FOUND;
}

//this method add fan page to system.
bool System::addFanPage(const char* name)
{
	if (isFanPageAlreadyExist(name) == NOT_FOUND )
	{
		fanPage* m = new fanPage(name);
		if (allFanPagesArrLogSize == allFanPagesArrPhySize)
		{
			allFanPagesArrPhySize *= 2;
			allFanPagesArr = (fanPage**)reallocation(allFanPagesArr, allFanPagesArrPhySize, sizeof(Member*));
		}
		allFanPagesArr[allFanPagesArrLogSize++] = m;
		return true;
	}
	return false;
}

void System::addStatus(const char* name, Status* statusToAdd)
{
	int place = isMemberAlreadyExist(name);

	if (place != NOT_FOUND)
		allMembersArr[place]->addStatus(statusToAdd);
}

void System::addStatusToFanPage(const char* name, Status* statusToAdd)
{
	int place = isFanPageAlreadyExist(name);

	if (place != NOT_FOUND)
		allFanPagesArr[place]->addStatus(statusToAdd);
}
void System::showStatusesOfMember(const char* name) const
{
	int place = isMemberAlreadyExist(name);

	if (place != NOT_FOUND)
		allMembersArr[place]->printAllStatus();
}

void System::showStatusesOfFanPage(const char* name) const
{
	int place = isFanPageAlreadyExist(name);

	if (place != NOT_FOUND)
		allFanPagesArr[place]->printAllStatus();
}

void System::showLast10Statuses(const char* name) const
{
	int place = isMemberAlreadyExist(name);

	if (place != NOT_FOUND)
		allMembersArr[place]->printLast10Status();
}

bool System::friendShipLinkBetweenTwoMembers(int placeOfFirstMember, int PlaceOfMemberToAdd)
{
	return (allMembersArr[placeOfFirstMember]->AddMember(allMembersArr[PlaceOfMemberToAdd]));
}
bool System::deleteFriendShipBetweenTwoMembers(int placeOfFirstMember, int PlaceOfMemberToRemove)
{
	return (allMembersArr[placeOfFirstMember]->removeMember(allMembersArr[PlaceOfMemberToRemove]));
}
bool System::addMemberToFanPage(int placeOfFanPage, int PlaceOfMember)
{
	return (allFanPagesArr[placeOfFanPage]->addMemberToFanPage(allMembersArr[PlaceOfMember]));
}
bool System::deleteMemberFromFanPage(int placeOfFanPage, int PlaceOfMember)
{
	return (allFanPagesArr[placeOfFanPage]->deleteMemberFromFanPage(allMembersArr[PlaceOfMember]));
}
void System::showMembers() const
{
	for (int i = 0; i < allMembersArrLogSize; i++)
	{
		cout << i + 1 << ".";
		allMembersArr[i]->showMemberName();
	}
}
void System::showFanPages() const
{
	for (int i = 0; i < allFanPagesArrLogSize; i++)
	{
		cout << i + 1 << ".";
		allFanPagesArr[i]->printName();
	}
}
void System::showAllFriendsOfMember(const char* name) const
{
	int placeOfMember = isMemberAlreadyExist(name);
	if (placeOfMember != NOT_FOUND)
		allMembersArr[placeOfMember]->showMemberFriends();
	
}
void System::showAllFollowersOfFanPage(const char* name) const
{
	int placeOfFanPage = isFanPageAlreadyExist(name);
	if (placeOfFanPage != NOT_FOUND)
		allFanPagesArr[placeOfFanPage]->showMembersOfFanPage();
}
//d'tor
System::~System()
{
	for (int i = 0; i < allMembersArrLogSize; i++)
		delete allMembersArr[i];
	for (int i = 0; i < allFanPagesArrLogSize; i++)
		delete allFanPagesArr[i];

	delete[]allMembersArr;
	delete[] allFanPagesArr;
}