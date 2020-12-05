#pragma once
#include "SrtTag.h"

/*! Reverses the list*/
class SrtRevTag : public SrtTag
{
protected:
	virtual std::list<double> sort(const std::list<double>& data, const std::string& additional = "") override
	{
		std::list<double> result;
		auto begin = data.begin();
		auto end = data.end();

		if (begin != end)
		{
			for (auto it = --end; it != begin; --it)
				result.push_back(*it);

			result.push_back(*begin);
		}

		return result;
	}
};
