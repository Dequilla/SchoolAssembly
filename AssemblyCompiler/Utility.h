#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>

#include <bitset>

inline std::vector<std::string> splitString(std::string str, char delim = ' ')
{
	std::vector<std::string> elements;
	std::stringstream ss;
	ss.str(str);
	std::string item;
	while (std::getline(ss, item, delim))
	{
		elements.push_back(item);
	}

	return elements;
}

template<unsigned int nrOfBits>
inline std::string intToBinary(int input)
{
	// Translate integer to a binary representation
	return std::bitset<nrOfBits>(input).to_string();
}

// Removes a substr from the string
inline std::string removeSub(std::string str, std::string sub)
{
	int pos = str.find(sub);
	str.erase(pos, sub.size());
	return str;
}

inline bool isInteger(const std::string &s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '+'))) return false;

	char* p;
	strtol(s.c_str(), &p, 10);
	return (*p == 0);
}