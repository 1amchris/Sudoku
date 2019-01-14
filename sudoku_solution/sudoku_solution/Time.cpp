#include "Time.h"

void Time::_format_time()
{
	// Seconds
	int _seconds = seconds % 60;
	int _seconds_to_minutes = seconds / 60;
	minutes += _seconds_to_minutes;

	// Minutes
	int _minutes = minutes % 60;
	int _minutes_to_hours = minutes / 60;
	hours += _minutes_to_hours;

	// Hours
	int _hours = hours % 24;
	int _hours_to_day = hours / 60;
	days += _hours_to_day;
}

Time::Time()
{
	days = 0;
	hours = 0;
	minutes = 0;
	seconds = 0;
}

Time::Time(unsigned int _days, unsigned int _hours, unsigned int _minutes, unsigned int _seconds)
{
	days = _days;
	hours = _hours;
	minutes = _minutes;
	seconds = _seconds;

}

Time Time::operator=(Time other)
{
	Time new_time;
	new_time.days = other.days;
	new_time.hours = other.hours;
	new_time.minutes = other.minutes;
	new_time.seconds = other.seconds;


	return new_time;
}

std::string Time::time()
{
	format_time();

	return str_manip::int_to_string(days) + ':' +
		str_manip::int_to_string(hours) + ':' +
		str_manip::int_to_string(minutes) + ':' +
		str_manip::int_to_string(seconds);
}
