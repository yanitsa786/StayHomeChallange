#pragma once
#include "Users.h"
#include <iostream>
#include <string>


Users::User(unsigned short id, char* name, unsigned short age, char* email)
{
	this->validateName(name);
	this->validateAge(age);
	this->validateEmail(email);

	this->id = id;
	strcpy(this->name, name);
	this->age = age;
	strcpy(this->email, email);
}

Users::User(unsigned short id, char* name, unsigned short age)
{
	this->validateName(name);
	this->validateAge(age);

	this->id = id;
	strcpy(this->name, name);
	this->age = age;
	strcpy(this->email, "");
}

Users::User(unsigned short id, char* name, char* email)
{
	this->validateName(name);
	this->validateEmail(email);

	this->id = id;
	strcpy(this->name, name);
	this->age = 0;
	strcpy(this->email, "");
}

void Users::print()
{
	std::cout << "ID: " << this->getId() << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;

	std::cout << "Age: ";
	if (this->getAge() == 0)
	{
		std::cout << "Unknown" << std::endl;
	}
	else
	{
		std::cout << this->getAge() << std::endl;
	}

	std::cout << "Email: ";
	if (!strcmp(this->getEmail(), ""))
	{
		std::cout << "Unknown" << std::endl;
	}
	else
	{
		std::cout << this->getEmail() << std::endl;
	}
}

void Users::addChallange(Challange* challenge)
{
	this->activeChallenges[this->activeChallengesCount] = challenge;
	this->activeChallengesCount++;
}



char* Users::getName()
{
	return this->name;
}

short Users::getAge()
{
	return this->age;
}

char* Users::getEmail()
{
	return this->email;
}

short Users::getId()
{
	return this->id;
}

bool Users::validateName(char* name)
{
	return true;
}

bool Users::validateAge(short age)
{
	return true;
}

bool Users::validateEmail(char* email)
{
	return true;
}
