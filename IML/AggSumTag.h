#pragma once
#include "AggTag.h"

class AggSumTag : public AggTag
{
protected:
	virtual double aggregate(const std::list<double>& data) override
	{
		double result = 0;

		for (auto it = data.begin(); it != data.end(); ++it)
			result += *it;

		return result;
	}
};
