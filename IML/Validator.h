#pragma once
#include <string>

static class Validator
{
private:
	static bool isArgument(const std::string&);
	static bool isInteger(const std::string&);
public:
	static bool isOpeningTagWithParam(const std::string&);
	static bool isOpeningTagWithNoParam(const std::string&);
	static bool isClosingTag(const std::string&);
	static bool isRealNumber(const std::string&);
	static bool isRealNumberArgument(const std::string&);
	static bool isIntegerArgument(const std::string&);
	static bool isSortingOrderArgument(const std::string&);
};
