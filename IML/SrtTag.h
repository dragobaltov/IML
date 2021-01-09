#pragma once
#include "Tag.h"

class SrtTag : public Tag
{
protected:
	virtual std::vector<double> sort(const std::vector<double>& data) = 0;
public:
	virtual std::vector<double> evaluate(const std::vector<double>& data) override
	{
		return sort(data);
	}
};
