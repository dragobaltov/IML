#pragma once
#include "Tag.h"

static class TagsFactory
{
public:
	static Tag* createTagWithNoParam(const std::string&);
	static Tag* createTagWithParam(const std::string&, const std::string&);
};
