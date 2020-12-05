#pragma once
#include "SrtTag.h"

/*! Sorts the list in ascending order(if the given parameter is ASC) or
* in descending order(if the given parameter is DSC) 
*/
class SrtOrdTag : public SrtTag
{
protected:
	virtual std::list<double> sort(const std::list<double>& data, const std::string& additional) override
	{
		std::list<double> result = data;

		if (additional == "ASC")
		{
			result.sort();
		}
		else
		{
			result.sort(std::greater<double>());
		}

		return result;
	}
};
