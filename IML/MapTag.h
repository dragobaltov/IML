#pragma once
#include "Tag.h"
#include <functional>

class MapTag : public Tag
{
private:
	std::list<double> map(const std::list<double>& data, double additional)
	{
		std::list<double> result;

		for (auto it = data.begin(); it != data.end(); ++it)
		{
			result.push_back(mappingFunc(*it, additional));
		}

		return result;
	}
protected:
	virtual double mappingFunc(double x, double y) = 0;
public:
	// Inherited via Tag
	virtual std::list<double> evaluate(const std::list<double>& data, const std::string& additional) override
	{
		double additionalArg = std::stod(additional);

		return map(data, additionalArg);
	}
};
