#pragma once
#include <string>
#include "Challange.cpp"

class Challange
{
private:
	
	char* name; //dynamic because the app is available worldwide
	char* status;
	double rating;
	unsigned int timesCalled;
	unsigned int timesCompleted;

	void deleteMemory(const char*);
	char* copyMemory(const char*);
	bool validateName(char* name);

public:
	Challange();
	Challange(const char*);
	Challange(const Challange&);
	Challange(const char*, unsigned int, unsigned int, double);
	Challange(const char*, const char*, unsigned int, unsigned int, double);
	Challange(char* name);
	~Challange();

	const char* getName() const;
	const unsigned getTimesCalled() const;
	double getRating();

	void rate(double rating);
	void nStatus();

	void print() const;

	
};
