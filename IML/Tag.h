#pragma once
#include <vector>
#include <string>
#include "StringTags.h"

class Tag
{
public:
	virtual bool closingTagIsValid(const std::string&) = 0;
	virtual std::vector<double> evaluate(const std::vector<double>& data) = 0;
};
