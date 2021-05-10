#pragma once
#include "ManageChallangesUsers&Id.cpp"
#include "Challange.h"

class ManageChallanges
{
private:
	Challenge* challenges[1024];
	short countChallenges;
public:
	ManageChallanges();

	Challenge* createChallange(char* name); //function to create challange by name
	Challenge* getChallangeByName(char* name);

	Challenge* getAllChallanges();
	short getChallangesCount();

	~ManageChallanges();

};

class IdCollector {
private:
	unsigned short lastId;
public:
	IdCollector();

	unsigned short getLastId();
	void updateLastId();
};


class ManageUsers
{
private:
	Users* users[1024];
	short countUsers;
	IdCollector idCollector;
	void addUser(Users* users);
public:
	ManageUsers();

	void createUser(char* name, unsigned short age, char* email);
	void createUser(char* name, unsigned short age);
	void createUser(char* name, char* email);
	

	Users* getUserById(unsigned short id);
	Users* getUserByName(char* name);

	~ManageUsers();
};
