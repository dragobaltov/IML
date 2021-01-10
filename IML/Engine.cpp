#include <iostream>
#include "Engine.h"

Engine::Engine(const Tokenizer& tokenizer, const Parser& parser) :
	m_tokenizer{ tokenizer }, m_parser{ parser } {}

void Engine::run()
{
	std::string input;
	std::getline(std::cin, input);

	try
	{
		std::vector<std::string> tokens = m_tokenizer.tokenize(input);
		std::vector<double> result = m_parser.parse(tokens);

		printResult(result);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}

void Engine::printResult(const std::vector<double>& result) const
{
	for (double num : result)
	{
		std::cout << num << ' ';
	}
}