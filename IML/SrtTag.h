#pragma once
#include "Tag.h"

class SrtTag : public Tag
{
protected:
	virtual std::list<double> sort(const std::list<double>& data, const std::string& additional = "") = 0;
public:
	virtual std::list<double> evaluate(const std::list<double>& data, const std::string& additional = "") override
	{
		return sort(data, additional);
	}
};
