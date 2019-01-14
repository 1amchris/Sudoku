#pragma once
#include <string>
#include "str_manip.h"

class Time
{
	unsigned int days;
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;

	void _format_time();

public :
	Time();
	Time(unsigned int days, unsigned int hours, unsigned int minutes, unsigned int seconds);

	Time operator=(Time other);
	std::string time();

};

