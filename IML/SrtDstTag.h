#pragma once
#include "SrtTag.h"
#include <unordered_set>

/*! Returns distinct elements of the given vector*/
class SrtDstTag : public SrtTag
{
	virtual std::vector<double> sort(const std::vector<double>& data) override
	{
		std::unordered_set<double> distinct(data.begin(), data.end());
		std::vector<double> result(distinct.begin(), distinct.end());

		return result;
	}

public:
	virtual bool closingTagIsValid(const std::string& tag) const override
	{
		return tag == '/' + StringTags::SRT_DST;
	}
};
