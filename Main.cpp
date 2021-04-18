
#pragma once
#include "ManageChallangesUsers&Id.h"
#include "Users.h"
#include "Challange.h"



int main() {
	ManageUsers manageUsers;
	ManageChallanges manageChallanges;

	CreateChallange* createChallange = new CreateChallange(&manageChallange, &manageUsers);
	ListBy* list_by = new ListBy(&manageChallanges);
	ProfileInfo* profile_info = new ProfileInfo(&manageUsers);
	Register* register_user = new Register(&manageUsers);

	return 0;

}