#include "Utility.h"
#include "Compiler.h"
#include <fstream>
#include <unordered_map>

int main(int argc, char** argv)
{
	std::cout << " -- Parsing arguments" << std::endl;

	std::unordered_map<std::string, std::string> arguments;
	
	// Parse arguments
	for (int i = 0; i < argc; i++)
	{
		if (argv[i][0] == 'i' && argv[i][1] == 'n')
			arguments.emplace("in", splitString(std::string(argv[i]), ':')[1]);
		
		else if (argv[i][0] == 'o' && argv[i][1] == 'u' && argv[i][2] == 't')
			arguments.emplace("out", splitString(std::string(argv[i]), ':')[1]);
	}

	bool hasArgs = true;
	if (arguments.count("in") < 1 || arguments.count("out") < 1)
	{
		std::cout << "ERROR: You need to specify the input and output file, example: AssemblyCompiler.exe in:input.asm out:output.abin" << std::endl;
		hasArgs = false;
	}

	if (hasArgs)
	{
		std::cout << " -- Reading input --> \"" + arguments.at("in") + "\"" << std::endl;
		std::string output = readFile(arguments.at("in"));
		
		std::cout << " -- Compiling..." << std::endl;
		std::string translated = translate(output);
		
		std::cout << " -- Writing to outputfile --> \"" + arguments.at("out") + "\"" << std::endl;
		writeFile(arguments.at("out"), translated);
	}

	std::cout << "DONE!" << std::endl;

#ifdef _DEBUG
	system("PAUSE");
#endif

	return 0;
}