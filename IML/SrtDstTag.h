#pragma once
#include "SrtTag.h"
#include <unordered_set>

/*! Returns distinct elements of the given list*/
class SrtDstTag : public SrtTag
{
	virtual std::list<double> sort(const std::list<double>& data, const std::string& additional = "") override
	{
		std::unordered_set<double> distinct(data.begin(), data.end());
		std::list<double> result(distinct.begin(), distinct.end());

		return result;
	}
};
