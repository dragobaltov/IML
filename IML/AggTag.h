#pragma once
#include "Tag.h"

class AggTag : public Tag
{
protected:
	virtual double aggregate(const std::list<double>& data) = 0;
public:
	virtual std::list<double> evaluate(const std::list<double>& data, const std::string& additional) override
	{
		double result = aggregate(data);

		std::list<double> resultList;
		resultList.push_back(result);

		return resultList;
	}
};
