#pragma once
#include "SrtTag.h"
#include <unordered_set>

/*! Returns distinct elements of the given vector*/
class SrtDstTag : public SrtTag
{
	virtual std::vector<double> sort(const std::vector<double>& data) override
	{
		std::vector<double> result(data.begin(), data.end());
		std::unordered_set<double> s;

		auto end = std::remove_if(result.begin(), result.end(),
			[&s](double const& i) {return !s.insert(i).second; });

		result.erase(end, result.end());

		return result;
	}

public:
	virtual bool closingTagIsValid(const std::string& tag) const override
	{
		return tag == '/' + StringTags::SRT_DST;
	}
};
