#pragma once
#include <stack>
#include "Tag.h"

class Parser
{
private:
	std::stack<Tag*> tagsStack;
	std::stack<std::vector<double>> numsStack;
public:
	std::vector<double> parse(const std::vector<std::string>&);
};