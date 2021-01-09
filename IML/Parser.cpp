#include "Parser.h"
#include "TagsFactory.h"
#include "Validator.h"

std::vector<double> Parser::parse(const std::vector<std::string>& tokens)
{
	size_t tokensSize = tokens.size();
	bool lastTokenWasOpeningTag = false;

	for (size_t i = 0; i < tokensSize; ++i)
	{
		if (Validator::isOpeningTagWithNoParam(tokens[i]))
		{
			Tag* tag = TagsFactory::createTagWithNoParam(tokens[i]);
			tagsStack.push(tag);

			lastTokenWasOpeningTag = true;
		}
		else if (Validator::isOpeningTagWithParam(tokens[i]))
		{
			if (i == tokensSize - 1)
			{
				// throw error
			}

			Tag* tag = TagsFactory::createTagWithParam(tokens[i], tokens[i + 1]);
			tagsStack.push(tag);

			++i;
			lastTokenWasOpeningTag = true;
		}
		else if (Validator::isRealNumber(tokens[i]))
		{
			double num = std::stod(tokens[i]);

			if (numsStack.size() == 0 || lastTokenWasOpeningTag)
			{
				std::vector<double> newVector;
				newVector.push_back(num);
				numsStack.push(newVector);
			}
			else
			{
				numsStack.top().push_back(num);
			}

			lastTokenWasOpeningTag = false;
		}
		else if (Validator::isClosingTag(tokens[i]))
		{
			if (tagsStack.empty() || numsStack.empty() || !tagsStack.top()->closingTagIsValid(tokens[i]))
			{
				// throw error
			}

			std::vector<double> result = tagsStack.top()->evaluate(numsStack.top());
			tagsStack.pop();
			numsStack.pop();

			if (numsStack.empty())
			{
				numsStack.push(result);
			}
			else
			{
				numsStack.top().insert(numsStack.top().end(), result.begin(), result.end());
			}

			lastTokenWasOpeningTag = false;
		}
		else
		{
			//throw error
		}
	}

	if (!tagsStack.empty() || numsStack.size() != 1)
	{
		// throw error
	}

	return numsStack.top();
}