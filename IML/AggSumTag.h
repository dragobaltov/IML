#pragma once
#include "AggTag.h"

/*!Calculates the sum of the given values*/
class AggSumTag : public AggTag
{
protected:
	virtual double aggregate(const std::vector<double>& data) override
	{
		double result = 0;

		for (auto it = data.begin(); it != data.end(); ++it)
			result += *it;

		return result;
	}
public:
	virtual bool closingTagIsValid(const std::string& tag) const override
	{
		return tag == '/' + StringTags::AGG_SUM;
	}
};
