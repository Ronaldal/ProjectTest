#include "System.h"

#define SIZE 100
#define MEMBER 'M'


void cleanBuffer();
void printMenu();
void Running(int memberChoose, System& system);
char* getName();
void addFanPageToSystem(System& system,const char * name);
void addMemberToSystem(System& system, const char* name);
void addStatusToMemberOrFanPage(System & system, const char* name);
void viewAllStatusesOfMemberOrFanPage(System& system, const char* name);
void viewLast10Statuses(System& system, const char* name);
void friendShipLinkBetweenTwoMembers(System& system, const char* name);
void unfriendingBetweenTwoMembers(System& system, const char* name);
void addMemberToFanPage(System& system, const char* nameOfFanPage);
void deleteMemberFromFanPage(System& system, const char* name);
void showAllEntitiesRegisteredToSystem(System& system);
void showAllFriendsOfMemberOrFanPage(System& system, const char* name);