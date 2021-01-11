#include "Parser.h"
#include "TagsFactory.h"
#include "Validator.h"
#include "StringErrors.h"
#include <exception>

void Parser::deleteTag()
{
	delete tagsStack.top();
	tagsStack.pop();
}

std::vector<std::vector<double>> Parser::parse(const std::vector<std::string>& tokens)
{
	std::vector<std::vector<double>> results;
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
				throw std::exception(StringErrors::MISSING_ARGUMENT.c_str());
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
				throw std::exception(StringErrors::CLOSING_TAG_NOT_MATCHING_OPENING.c_str());
			}
			if (!tagsStack.top()->closingTagIsValid(tokens[i]))
			{
				throw std::exception(StringErrors::INVALID_CLOSING_TAG.c_str());
			}
			if (numsStack.empty())
			{
				throw std::exception(StringErrors::MISSING_NUMBERS_INPUT.c_str());
			}
			

			std::vector<double> result = tagsStack.top()->evaluate(numsStack.top());
			deleteTag();
			numsStack.pop();

			if (numsStack.empty())
			{
				if (tagsStack.empty())
				{
					results.push_back(result);
				}
				else
				{
					numsStack.push(result);
				}
			}
			else
			{
				numsStack.top().insert(numsStack.top().end(), result.begin(), result.end());
			}

			lastTokenWasOpeningTag = false;
		}
		else
		{
			throw std::exception(StringErrors::INVALID_INPUT.c_str());
		}
	}

	if (!tagsStack.empty())
	{
		throw std::exception(StringErrors::INVALID_INPUT.c_str());
	}

	return results;
}