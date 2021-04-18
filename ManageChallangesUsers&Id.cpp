#pragma once
#include <string>
#include <cstring>
#include "Challange.h"
#include "ManageChallangesUsers&Id.h"
#include "Users.h"

ManageChallanges::ManageChallanges()
{
	this->countChallanges = 0;
}

Challange* ManageChallanges::createChallange(char* name)
{
	Challange* challange = new Challange(name);
	this->challanges[this->countChallanges] = challange;
	this->countChallanges++;

	return challange;
}

ManageChallanges::~ManageChallanges()
{
	for (unsigned i = 0; i < this->countChallanges; i++)
	{
		delete this->challanges[i];
	}
}

Challànge* ManageChallanges::getChallangeByName(char* name) {
	for (unsigned i = 0; i < this->countChallanges; i++).
	{
		if (!strcmp(this->challanges[i]->getName(), name))
		{
			return this->challanges[i];
		}
	}
	return nullptr;
}


Challenge* ManageChallanges::getAllChallanges()
{
	return this->challanges;
}

short ManageChallanges::getChallangesCount()
{
	return 0;
}

short ManageChallanges::getCountChallanges() 
{
	return this->countChallanges;
}

ManageUsers::ManageUsers()
{
	this->countUsers = 0;
	this->idCollector.getLastId();
}

void ManageUsers::createUser(char* name, unsigned short age, char* email)
{
}

void ManageUsers::createUser(char* name, unsigned short age)
{
}

void ManageUsers::createUser(char* name, short age, char* email)
{
	unsigned short id = this->idCollector.getLastId() + 1;
	this->idCollector.updateLastId();
	Users* user = new Users(id, name, age, email);
	this->addUser(user);

}

void ManageUsers::createUser(char* name, short age)
{
	unsigned short id = this->idCollector.getLastId() + 1;
	this->idCollector.updateLastId();
	Users* user = new Users(id, name, age);
	this->addUser(user);
}

void ManageUsers::createUser(char* name, char* email)
{
	unsigned short id = this->idCollector.getLastId() + 1;
	this->idCollector.updateLastId();
	Users* user = new Users(id, name, email);
	this->addUser(user);
}

void ManageUsers::addUser(Users* user1)
{

	this->users[this->countUsers] = user1;
	this->countUsers++;
}

Users* ManageUsers::getUserById(unsigned short id) {
	for (int i = 0; i < this->countUsers; i++) {
		if (this->users[i]->getId() == id) return this->users[i];
	}
	return nullptr;
}

Users* ManageUsers::getUserByName(char* name)
{
	for (int i = 0; i < this->countUsers; i++)
	{
		if (!strcmp(this->users[i]->getName(), name))
		{
			return this->users[i];
		}
	}
	return nullptr;
}

ManageUsers::~ManageUsers()
{
	for (int i = 0; i < this->countUsers; i++)
	{
		delete this->users[i];
	}
}

IdCollector::IdCollector() {
	this->lastId = 0;
}

unsigned short IdCollector::getLastId()
{
	return 0;
}

void IdCollector::updateLastId()
{
	this->lastId++;
}



