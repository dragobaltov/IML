#pragma once
#include "AggTag.h"

class AggProTag : public AggTag
{
protected:
	virtual double aggregate(const std::list<double>& data) override
	{
		double result = 1;

		for (auto it = data.begin(); it != data.end(); ++it)
			result *= *it;

		return result;
	}
};
