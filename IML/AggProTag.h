#pragma once
#include "AggTag.h"

/*!Calculates the product of the given values*/
class AggProTag : public AggTag
{
protected:
	virtual double aggregate(const std::vector<double>& data) override
	{
		double result = 1;

		for (auto it = data.begin(); it != data.end(); ++it)
			result *= *it;

		return result;
	}
public:
	virtual bool closingTagIsValid(const std::string& tag) const override
	{
		return tag == '/' + StringTags::AGG_PRO;
	}
};
