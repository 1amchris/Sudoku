#pragma once
class Case
{
	void _init();

	unsigned short int _value;
	unsigned short int _answer;

	bool _complete;

public:
	Case();
	Case(unsigned short int);
	~Case();

	void set_Value(unsigned short int);
	bool get_complete();
	bool validate_Answer();
};

