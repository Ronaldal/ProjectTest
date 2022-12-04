#include "BillBoard.h"
using namespace std;

//c'tor
BillBoard::BillBoard()
{
	logSize = 0;
	phySize = 1;
	statusArr = new Status * [phySize];
}
// this function adding status to the statuses array of entity.
//because there isnt size to the array we using the logical physical algorythem.
void BillBoard::addStatus( Status* statusToAdd)
{
	if (logSize == phySize)
	{
		this->updatePhySize();
		//this->myRealloc();
		statusArr = (Status**)reallocation(statusArr,phySize,sizeof(Status*));
	}
	statusArr[logSize] = statusToAdd;
	this->updateLogSize();
}

// function for print the last 10 statuses of member.
void BillBoard::showMemberBillboard() const
{
	int i;
	if (logSize < 10)
	{
		for (i = 0; i < logSize; i++)
		{
			statusArr[i]->showStatus();
		}
	}
	else
	{
		for (i = logSize - 10; i < logSize; i++)
		{
			statusArr[i]->showStatus();
		}
	}
}
void BillBoard::showBillBoard() const
{
	for (int i = 0; i < logSize; i++)
	{
		statusArr[i]->showStatus();
	}
}

void BillBoard::updateLogSize()
{
	logSize++;
}
void BillBoard::updatePhySize()
{
	phySize *= 2;
}
//d'tor for free every status and the array itself.
BillBoard::~BillBoard()
{
	for (int i = 0; i < logSize; i++)
		delete statusArr[i];
	delete[]statusArr;
}



