#pragma once
#include <string>
#include "Challange.h"
#include "User.cpp"

class Users {
private:
	unsigned short id;
	char name[200];
	unsigned short age;
	char email[100];
	Challenge* activeChallanges[65535];
	short activeChallangesCount;

	bool validateName(char* name);
	bool validateAge(short age);
	bool validateEmail(char* email);

public:
	User(unsigned short id, char* name, unsigned short age, char* email);
	User(unsigned short id, char* name, unsigned short age);
	User(unsigned short id, char* name, char* email);

	void print();

	void addChallange(Challange* challenge);

	short getId();
	char* getName();
	short getAge();
	char* getEmail();
};
