#ifndef __SYSTEM_H
#define __SYSTEM_H

#define NOT_FOUND -1
#include "fanPage.h"
#include "Member.h"

//the class system is a kind of an admin of the whole system.
//it contains all the registered entities.

class System
{
	Member** allMembersArr;
	fanPage** allFanPagesArr;

	int allMembersArrLogSize, allMembersArrPhySize;

	int allFanPagesArrLogSize, allFanPagesArrPhySize;

public :
	System();
	bool addMember(const Date& birthDate,const char* name);
	bool addFanPage(const char* name);
	void addStatus(const char* name, Status* statusToAdd);
	void addStatusToFanPage(const char* name, Status* statusToAdd);
	bool addMemberToFanPage(int placeOfFanPage, int PlaceOfMember);

	int isMemberAlreadyExist(const char* name)  const;
	int isFanPageAlreadyExist(const char* name) const;

	void showStatusesOfMember(const char* name) const;
	void showStatusesOfFanPage(const char* name)const;
	void showLast10Statuses(const char* name)   const;
	void showMembers()                          const;
	void showFanPages()                         const;
	void showAllFriendsOfMember(const char* name)const;
	void showAllFollowersOfFanPage(const char* name) const;

	bool friendShipLinkBetweenTwoMembers(int placeOfFirstMember, int PlaceOfMemberToAdd);

	bool deleteFriendShipBetweenTwoMembers(int placeOfFirstMember, int PlaceOfMemberToRemove);
	bool deleteMemberFromFanPage(int placeOfFanPage, int PlaceOfMember);
	
	~System();
};



#endif // !__SYSTEM_H



