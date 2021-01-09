#pragma once
#include "Tag.h"

class AggTag : public Tag
{
protected:
	virtual double aggregate(const std::vector<double>& data) = 0;
public:
	virtual std::vector<double> evaluate(const std::vector<double>& data) override
	{
		double result = aggregate(data);

		std::vector<double> resultList;
		resultList.push_back(result);

		return resultList;
	}
};
