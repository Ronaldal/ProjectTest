#ifndef __FANPAGE_H
#define __FANPAGE_H
#include "BillBoard.h"

class Member;//forward declartion

//The class fan page contains the name of the fan page, 
//the members whom liked the fan page
//and the billboard which contains the statuses array.

class fanPage
{
	char* name;
	Member** fanPageMembers;
	BillBoard fanPageBillBoard;
	int fanPageMembersArrLogSize, fanPageMembersArrPhySize;
public:
	fanPage(const char* name);

	bool addMemberToFanPage(Member* memberToAdd);
	bool deleteMemberFromFanPage(Member* memberToDelete);

	void showMembersOfFanPage() const;
	void updateFanPageMembersArrLogSize();
	void updateFanPageMembersArrPhySize();
	char* getFanPageName() const;
	void printName() const;

	bool pageLikedAlreadyByMember(Member* memberToAdd) const;
	void addStatus(Status* statusToAdd);
	void printAllStatus() const;

	~fanPage();

	

};
#endif // __FANPAGE_H
