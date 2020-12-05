#pragma once
#include <list>
#include <string>

class Tag
{
private:
	// function to validate additional parameters?
public:
	/*
	* 1. May wanna work with other data types -> template
	* 2. May wanna receive more than one additional parameter -> receive list of strings
	*/
	virtual std::list<double> evaluate(const std::list<double>& data, const std::string& additional = "") = 0;
};
