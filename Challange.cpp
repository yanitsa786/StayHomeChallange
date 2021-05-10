#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
#include "Challange.h"


const unsigned maxChallangeNameLength = 32; // # + 31 symbols 

Challange::Challange()
{
	this->name = copyMemory("");
	this->status = copyMemory("");
	this->rating = 0;
	this->timesCalled = 0;
}

Challange::Challange(const char* _name)
{
	if (strlen(_name) <= maxChallangeNameLength)
	{
		return; //stop execution
	}
	else
	{
		std::cout << "Error! Your challenge have to be max 32 symbols long, including #." << std::endl;
	}

	this->name;
    this->copyMemory(_name);
	this->status;
	this->copyMemory("new");
	this->timesCalled = 0;
	this->timesCompleted = 0;
	this->rating = 0;

}

Challange::Challange(const Challange& _other)
{
	this->name = this->copyMemory(_other.name);
	this->status = this->copyMemory(_other.status);
	this->timesCalled = _other.timesCalled;
	this->rating = _other.rating;
}

Challange::Challange(const char* _name, unsigned int _timesCalled, unsigned int _timesCompleted, double _rating)
{
	this->name = this->copyMemory(_name);
	this->timesCalled = _timesCalled;
	this->timesCompleted = _timesCompleted;
	this->rating = _rating;

	if (strlen(_name) <= maxChallangeNameLength)
	{
		return; 
	}
	else
	{
		std::cout << "Error! Your challenge must be max 32 symbols long, including #." << std::endl;
	}

	if (_rating >= -5.0 && _rating <= 10)
	{
		if (this->timesCalled > 10)
		{
			this->status = this->copyMemory("Old");
		}
		else if (this->timesCalled > 1) 
		{
			this->status = this->copyMemory("Quite recently");
		}
		else if (this->timesCalled == 1)
		{
			this->status = this->copyMemory("New");
		}
	}
	else
	{
		std::cout << "This challenge is not interesting." << std::endl; //not sure about this 
	}
}

Challange::Challange(const char* _name, const char* _status, unsigned int _timesCalled, unsigned int _timesCompleted, double _rating)
{
	
	this->name = this->copyMemory(_name);
	this->timesCalled = _timesCalled;
	this->timesCompleted = _timesCompleted;
	this->rating = _rating;
	this->status = this->copyMemory(_status);
}

bool Challange::validateName(char* name)
{
	if (maxChallangeNameLength <= 32)
	{
		return true;
	}
}

Challange::~Challange()
{
	this->deleteMemory("name");
	this->deleteMemory("status");
}


char* Challange(const char* source)
{
	char* temp = new char[strlen(source) + 1];
	strcpy_s(temp, strlen(source) + 1, source);
	return temp;
}

void Challange::deleteMemory(char const* toBeDeleted)
{
	if (strcmp(toBeDeleted, "status") == 0)
	{
		delete[] this->status; // will display "deleted status"
	}
	if (strcmp(toBeDeleted, "name") == 0)
	{
		delete[] this->name; // will display "deleted name"
	}
}

char* Challange::copyMemory(const char*)
{
	return nullptr;
}


const char* Challange::getName() const
{
	return this->name;
}

const unsigned Challange::getTimesCalled() const
{
	return this->timesCalled;
}

double Challange::getRating()
{
	return 0.0;
}


void Challange::rate(double _rating)
{
	double newRating = this->rating * this->timesCompleted;
	newRating += _rating;
	newRating /= (++this->timesCompleted);
	this->rating = newRating;
}

void Challange::nStatus() 
{
	this->timesCalled++;

	if (this->timesCalled > 10 && strcmp(this->status, "Old") != 0)
	{
		this->deleteMemory("status");
		this->status = this->copyMemory("Old");
	}
	else if (this->timesCalled > 1 && strcmp(this->status, "Quite recently") != 0)
	{
		this->deleteMemory("status");
		this->status = this->copyMemory("Quite recently");
	}
}

void Challange::print() const
{
	std::cout << this->name << " " << this->status << " " << this->rating << " " << this->timesCalled << " " << this->timesCompleted << "\n";
}


