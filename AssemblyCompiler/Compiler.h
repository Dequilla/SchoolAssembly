#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include "Utility.h"

inline std::string readFile(std::string path)
{
	std::ifstream file(path);
	std::string line, output;
	while (std::getline(file, line))
	{
		output.append(line + "\n");
	}

	return output;
}

inline void writeFile(std::string path, std::string content)
{
	std::ofstream out;
	out.open(path);

	std::string line;
	std::stringstream file(content);

	while (std::getline(file, line))
	{
		out << line << "\n";
	}

	out.close();
}

inline std::string removeBrackets(std::string str)
{
	return str = removeSub(removeSub(str, "["), "]");
}

// Translates assembly into machinecode
inline std::string translate(std::string assembly)
{
	std::string line, output;
	std::stringstream file(assembly);
	while (std::getline(file, line))
	{
		std::string first, second, outfirst, outsecond;
		std::vector<std::string> split = splitString(line, ' ');
		
		// Extract the assembly code
		if (split.size() > 0)
			first = split[0];
		else
			first = "";

		// Extract the assembly code
		if(split.size() > 1)
			second = split[1];
		else
			second = "";

		// Translate the first value
		if (first != "")
		{
			if (first == "LOAD")
			{
				outfirst = "0000";
				second = removeBrackets(second);
				outsecond = intToBinary<12>(std::stoi(second));
			}
			else if (first == "STORE")
			{
				outfirst = "0001";
				second = removeBrackets(second);
				outsecond = intToBinary<12>(std::stoi(second));
			}
			else if (first == "ADD")
			{ 
				outfirst = "0010";
				second = removeBrackets(second);
				outsecond = intToBinary<12>(std::stoi(second));
			}
			else if (first == "SUB")
			{
				outfirst = "0011";
				second = removeBrackets(second);
				outsecond = intToBinary<12>(std::stoi(second));
			}
			else if (first == "JUMP")
			{
				outfirst = "0100";
				outsecond = intToBinary<12>(std::stoi(second));
			}
			else if (first == "PJUMP")
			{
				outfirst = "0101";
				outsecond = intToBinary<12>(std::stoi(second));
			}
			else if (first == "IN")
			{
				outfirst = "0110";
				outsecond = "000000000000";
			}
			else if (first == "OUT")
			{
				outfirst = "0111";
				outsecond = "000000000000";
			}
			else if (first == "CALL")
			{
				outfirst = "1000";
				outsecond = intToBinary<12>(std::stoi(second));
			}
			else if (first == "RETURN")
			{
				outfirst = "1001";
				outsecond = "000000000000";
			}
			else if (isInteger(first))
			{
				outfirst = "0000";
				outsecond = intToBinary<12>(std::stoi(first));
			}
			output.append(outfirst + " " + outsecond + "\n");
		}
	}

	return output;
}