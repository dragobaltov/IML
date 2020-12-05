#pragma once
#include "SrtTag.h"

/*! Slices the list from the given index to the end*/
class SrtSlcTag : public SrtTag
{
protected:
	virtual std::list<double> sort(const std::list<double>& data, const std::string& additional) override
	{
		int index = std::stoi(additional);

		if (index >= data.size())
		{
			return std::list<double>();
		}

		std::list<double> result;
		auto it = data.begin();

		for (int i = 0; i < index; ++i)
			++it;

		for (; it != data.end(); ++it)
			result.push_back(*it);

		return result;
	}
};
