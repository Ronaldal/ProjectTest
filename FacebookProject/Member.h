#ifndef __MEMBER_H
#define __MEMBER_H
#include "BillBoard.h"
#include "Date.h"

class fanPage;

//the class member contains the member name, his birth of date,
//his members in array, the fan pages he like in array and the meber statuses.
class Member
{
private:
	char* name;
	const Date birthDate;
	BillBoard memberBillBoard;

	Member** memberFriends;
	int memberFriendArrLogSize, memberFriendArrPhySize;

	fanPage** fanPageTheMemberLike;
	int memberFanPageArrLogSize, memberFanPageArrPhySize;

public:

	Member(const char* name , const Date& birthDate);
	bool AddMember( Member* memberToAdd);
	bool removeMember( Member* const memberToRemove);

	bool AddFanPage(fanPage* fanPageToAdd);
	bool removeFanPage(fanPage* fanPageToRemove);

	void showFanPagesMemberLike() const;
	void showMemberName() const;
	void showMemberFriends() const;

	char* getMemberName() const;
	void addStatus(Status* statusToAdd);

	void printLast10Status() const;
	void printAllStatus() const;

	void updateFriendArrLogSize();
	void updateFriendArrPhySize();

	bool isFriendsAlready(Member* memberToAdd) const;
	bool pageLikedAlreadyByMember(fanPage* fanPageToAdd) const;

	~Member();

};
#endif // !__MEMBER_H
