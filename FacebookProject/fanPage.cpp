#include "fanPage.h"
#include "Member.h"
using namespace std;

//c'tor
fanPage::fanPage(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	fanPageMembersArrPhySize = 1;
	fanPageMembersArrLogSize = 0;
	fanPageMembers = new Member * [fanPageMembersArrPhySize];
}

//in this function we adding a member to fan page using the physical local algorithem.
//return true if the member succesfully added.
bool fanPage::addMemberToFanPage(Member* memberToAdd)
{
	if(!pageLikedAlreadyByMember(memberToAdd))
	{
		if (fanPageMembersArrLogSize == fanPageMembersArrPhySize)
		{
			this->updateFanPageMembersArrPhySize();
			fanPageMembers = (Member**)reallocation(fanPageMembers, fanPageMembersArrPhySize, sizeof(Member*));
		}
		
		fanPageMembers[fanPageMembersArrLogSize] = memberToAdd;
		this->updateFanPageMembersArrLogSize();
		memberToAdd->AddFanPage(this);//after we add a member to a fan page we want to add the fan page to member.
		return true;
	}
	return false;
}

//this method delete member from fan page.
//return true if the member succesfuly removed.
bool fanPage::deleteMemberFromFanPage(Member* memberToDelete)
{
	bool found = false;
	for (int i = 0; i < fanPageMembersArrLogSize && !found; i++)
	{
		if (fanPageMembers[i] == memberToDelete)//if we find the member we want to remove
		{
			fanPageMembers[i] = fanPageMembers[fanPageMembersArrLogSize - 1]; //we take the last member in the array and point him from the place of the removed member.
			fanPageMembers[fanPageMembersArrLogSize - 1] = nullptr;// because of the previous line we put in the last pot of the array null.
			found = true;
			fanPageMembersArrLogSize--;
			memberToDelete->removeFanPage(this);//after we delete a member from a fan page we want to delete the fan page from the member array.
		}
	}
	return found;
}

//method to check if the page liked already by member.
bool fanPage::pageLikedAlreadyByMember(Member* memberToAdd) const
{
	for (int i = 0; i < fanPageMembersArrLogSize; i++)
	{
		if (fanPageMembers[i] == memberToAdd)
		{
			return true;
		}
	}
	return false;
}
void fanPage:: updateFanPageMembersArrLogSize()
{
	fanPageMembersArrLogSize++;
}
void fanPage:: updateFanPageMembersArrPhySize()
{
	fanPageMembersArrPhySize *= 2;
}

//print the members who liked certain fan page.
void fanPage::showMembersOfFanPage() const
{
	cout << "Fan page name :" << name << endl;
	cout <<"Liked by:" << endl;

	for (int i = 0; i < fanPageMembersArrLogSize; i++)
	{
		cout <<i+1<< ". ";
		fanPageMembers[i]->showMemberName();
	}
}

void fanPage::addStatus(Status* statusToAdd)
{
	fanPageBillBoard.addStatus(statusToAdd);
}
void fanPage::printAllStatus() const
{
	fanPageBillBoard.showBillBoard();
}
void fanPage::printName() const
{
	cout << name << endl;
}
//d'tor
fanPage::~fanPage()
{
	delete name;
	delete[]fanPageMembers;
}
char* fanPage::getFanPageName() const
{
	return name;
}