#include "Member.h"
#include "fanPage.h"
using namespace std;

//c'tor for member.
//in this method we allocate the member friends array and the fan pages array he like.
Member::Member(const char* name, const Date& birthDate) : birthDate(birthDate)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	memberFriendArrLogSize = 0;
	memberFriendArrPhySize = 1;

	memberFriends = new Member * [memberFriendArrPhySize];

	memberFanPageArrLogSize = 0;
	memberFanPageArrPhySize = 1;
	fanPageTheMemberLike = new fanPage * [memberFanPageArrPhySize];
}

char* Member::getMemberName() const
{
	return name;
}
//in this function we are adding members to each other.
bool Member::AddMember( Member* memberToAdd)
{
	if (!isFriendsAlready(memberToAdd))//First we check if the member is already friend
	{
		if (memberFriendArrLogSize == memberFriendArrPhySize)
		{
			this->updateFriendArrPhySize();
			memberFriends = (Member**)reallocation(memberFriends, memberFriendArrPhySize, sizeof(Member*));
		}
		memberFriends[memberFriendArrLogSize] = memberToAdd;
		this->updateFriendArrLogSize();

		/*Because the membership is mutual, 
		we will add the friend who activated the function to the friend who needs to be added*/
		memberToAdd->AddMember(this);
		return true;
	}
	return false;
}

//The function gets a member and returns true if the member to be added is in the member array else returns false
bool Member::isFriendsAlready(Member* memberToAdd) const
{
	for (int i = 0; i < memberFriendArrLogSize; i++)
	{
		if (memberFriends[i] == memberToAdd)
			return true;
	}
	return false;
}

bool Member::pageLikedAlreadyByMember(fanPage* fanPageToAdd) const
{
	for (int i = 0; i < memberFanPageArrLogSize; i++)
	{
		if(fanPageTheMemberLike[i]==fanPageToAdd)
			return true;
	}
	return false;
}

//The function gets a member and removes him from the array  
bool Member:: removeMember(Member* const memberToRemove)
{
	bool found = false;
	for (int i = 0; i < memberFriendArrLogSize && !found; i++)
	{
		if (memberFriends[i] == memberToRemove)
		{//we swaping the memberToRemove insted the last member 
			memberFriends[i] = memberFriends[memberFriendArrLogSize - 1];
			memberFriends[memberFriendArrLogSize - 1] = nullptr;//And then we do placement of nullptr
			found = true;
			this->memberFriendArrLogSize--;
		}
	}
	/*Because the membership is mutual,
		we will remove the friend who activated the function to the friend who needs to be removed*/
	if (found)
		memberToRemove->removeMember(this);
	return found;
}

//This function add a fan page to member.
bool Member::AddFanPage(fanPage* fanPageToAdd) 
{
	if (!pageLikedAlreadyByMember(fanPageToAdd))
	{
		if (memberFanPageArrLogSize == memberFanPageArrPhySize)
		{
			memberFanPageArrPhySize *= 2;
			fanPageTheMemberLike = (fanPage**)reallocation(fanPageTheMemberLike, memberFanPageArrPhySize, sizeof(fanPage*));
		}
		fanPageTheMemberLike[memberFanPageArrLogSize] = fanPageToAdd;
		memberFanPageArrLogSize++;
		fanPageToAdd->addMemberToFanPage(this);//beacuse its mutual.
		return true;
	}
	return false;
}
//this method remove a fan page from member.
bool Member::removeFanPage(fanPage* fanPageToRemove)
{
	for (int i = 0; i < memberFanPageArrLogSize; i++)
	{
		if (fanPageTheMemberLike[i] == fanPageToRemove)
		{
			fanPageTheMemberLike[i] = fanPageTheMemberLike[memberFanPageArrLogSize - 1];//same as fan page.
			fanPageTheMemberLike[memberFanPageArrLogSize - 1] = nullptr;//same as fan page.
			memberFanPageArrLogSize--;
			fanPageToRemove->deleteMemberFromFanPage(this);//mutual
			return true;
		}
	}
	return false;
}


void Member::updateFriendArrLogSize()
{
	memberFriendArrLogSize++;
}
void Member::updateFriendArrPhySize()
{
	memberFriendArrPhySize *= 2;
}


void Member::addStatus(Status* statusToAdd)
{
	memberBillBoard.addStatus(statusToAdd);
}

void Member::printLast10Status() const
{
	cout << "\nThe last 10 status of " << name << "'s friends :" << endl;
	for (int i = 0; i < memberFriendArrLogSize; i++)
	{
		cout << i + 1 << ". "<< memberFriends[i]->name<<"'s statuses are:"<<endl;
		memberFriends[i]->memberBillBoard.showMemberBillboard();
	}
}

void Member::printAllStatus() const
{
	memberBillBoard.showBillBoard();
}

void Member::showMemberFriends() const
{
	cout << "Member name:" << name << endl;
	cout << "His Friends: " << endl;
	for (int i = 0; i < memberFriendArrLogSize; i++)
	{
		cout << i + 1 << ". " << memberFriends[i]->name << endl;
	}
}

void Member::showMemberName() const
{
	cout << name << endl;
}

void Member::showFanPagesMemberLike() const
{
	cout << "Member name: " << name << endl;
	cout << "The fan pages he/she like: " << endl;
	for (int i = 0; i < memberFanPageArrLogSize; i++)
	{
		cout << i + 1 << ".";
		fanPageTheMemberLike[i]->printName();
	}
}

Member::~Member()
{
	delete name;
	delete[] memberFriends;
}