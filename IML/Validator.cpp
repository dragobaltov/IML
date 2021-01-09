#include "Validator.h"
#include "StringTags.h"

bool Validator::isOpeningTagWithParam(const std::string& str)
{
	return str == StringTags::MAP_INC || str == StringTags::MAP_MLT || 
		   str == StringTags::SRT_ORD || str == StringTags::SRT_SLC;
}

bool Validator::isOpeningTagWithNoParam(const std::string& str)
{
	return str == StringTags::AGG_AVG || str == StringTags::AGG_FST || str == StringTags::AGG_LST || 
		   str == StringTags::AGG_PRO || str == StringTags::AGG_SUM ||
		   str == StringTags::SRT_DST || str == StringTags::SRT_REV;
}

bool Validator::isClosingTag(const std::string& str)
{
	return str.size() > 0 && str[0] == '/' &&
		(isOpeningTagWithNoParam(str.substr(1)) || isOpeningTagWithParam(str.substr(1)));
}

bool Validator::isRealNumber(const std::string& str)
{
	char* p;
	double converted = std::strtod(str.c_str(), &p);

	return !(*p);
}

bool Validator::isArgument(const std::string& str)
{
	size_t size = str.size();

	return size > 2 && str[0] == '\"' && str[size - 1] == '\"';
}

bool Validator::isRealNumberArgument(const std::string& str)
{
	return isArgument(str) && isRealNumber(str.substr(1, str.size() - 2));
}

bool Validator::isInteger(const std::string& str)
{
	char* p;
	long converted = strtol(str.c_str(), &p, 10);
	
	return !(*p);
}

bool Validator::isIntegerArgument(const std::string& str)
{
	return isArgument(str) && isInteger(str.substr(1, str.size()- 2));
}

bool Validator::isSortingOrderArgument(const std::string& str)
{
	if (!isArgument(str))
	{
		return false;
	}

	std::string order = str.substr(1, str.size() - 2);

	return order == StringTags::ASC_ORDER || order == StringTags::DSC_ORDER;
}