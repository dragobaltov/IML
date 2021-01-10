#include "Parser.h"
#include "TagsFactory.h"
#include "Validator.h"
#include <exception>

void Parser::deleteTag()
{
	delete tagsStack.top();
	tagsStack.pop();
}

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
				throw std::exception("Missing tag argument!");
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
			if (tagsStack.empty())
			{
				throw std::exception("Closing tag missing opening tag!");
			}
			if (!tagsStack.top()->closingTagIsValid(tokens[i]))
			{
				throw std::exception("Invalid closing tag!");
			}
			if (numsStack.empty())
			{
				throw std::exception("No input numbers provided!");
			}
			

			std::vector<double> result = tagsStack.top()->evaluate(numsStack.top());
			deleteTag();
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
			throw std::exception("Invalid input!");
		}
	}

	if (!tagsStack.empty() || numsStack.size() != 1)
	{
		throw std::exception("Invalid input!");
	}

	return numsStack.top();
}