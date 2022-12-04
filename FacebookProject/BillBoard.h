#ifndef __BILLBOARD_H
#define __BILLBOARD_H

#include "Status.h"
#include "myRealloc.h"

// The class Billboard is for saving every member or fan page the statuses they have.
class BillBoard
{
private:
	Status** statusArr;
	int logSize, phySize;
public:
	BillBoard();
	void addStatus( Status* statusToAdd);

	void showMemberBillboard()  const;
	void showBillBoard() const;

	void updateLogSize();
	void updatePhySize();

	~BillBoard();
	
};

#endif // !__BILLBOARD_H
