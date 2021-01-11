#pragma once
#include "AggTag.h"

/*!Calculates the average of the given values*/
class AggAvgTag : public AggTag
{
protected:
	virtual double aggregate(const std::vector<double>& data) override
	{
		double result = 0;

		for (auto it = data.begin(); it != data.end(); ++it)
			result += *it;

		return result / data.size();
	}
public:
	virtual bool closingTagIsValid(const std::string& tag) const override
	{
		return tag == '/' + StringTags::AGG_AVG;
	}
};
