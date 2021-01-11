#include <iostream>
#include <fstream>
#include "Engine.h"
#include "StringErrors.h"

Engine::Engine(const Tokenizer& tokenizer, const Parser& parser) :
	m_tokenizer{ tokenizer }, m_parser{ parser } {}

void Engine::run()
{
	std::string inputFileName = getUserInput(INPUT_FILE_PROMPT);
	std::string outputFileName = getUserInput(OUTPUT_FILE_PROMPT);

	try
	{
		std::string input = readFile(inputFileName);

		std::vector<std::string> tokens = m_tokenizer.tokenize(input);
		std::vector<std::vector<double>> results = m_parser.parse(tokens);

		saveResults(outputFileName, results);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}

std::string Engine::getUserInput(const std::string& promptMessage) const
{
	std::string input;

	std::cout << promptMessage;
	std::getline(std::cin, input);

	return input;
}

std::string Engine::readFile(const std::string& fileName) const
{
	std::ifstream input;
	input.open(fileName, std::ios::in);

	if (!input.is_open())
	{
		throw std::exception(StringErrors::CANNOT_OPEN_INPUT_FILE.c_str());
	}

	std::string content((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));

	return content;
}

void Engine::saveResults(const std::string& fileName, const std::vector<std::vector<double>>& results) const
{
	std::ofstream output;
	output.open(fileName, std::ios::out);

	if (!output.is_open())
	{
		throw std::exception(StringErrors::CANNOT_OPEN_OUTPUT_FILE.c_str());
	}

	for (const auto& result : results)
	{
		for (const auto& value : result)
		{
			output << value << ' ';
		}
		output << '\n';
	}
}