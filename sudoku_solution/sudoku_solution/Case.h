#pragma once
class Case
{
	void _init();

	unsigned short int _value;
	unsigned short int _answer;

	bool _complete;
	bool _locked;

public:
	Case();
	Case(unsigned short int value);
	~Case();

	void set_value(unsigned short int value);
	void set_locked(bool value);
	bool get_complete();
	bool validate_answer();
};

