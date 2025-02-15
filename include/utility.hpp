#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <map>
#include <string>
#include <vector>
//# include <iostream>
#include <fstream>
#include <sstream>
#include <sys/stat.h>

namespace utils
{

	std::vector<std::string> split(std::string str, std::string delimiter);

	char **mapStringToArray(const std::map<std::string, std::string> &m);
	void freeArray(char **a);

	template <typename T> std::string numberToString(T pNumber)
	{
		std::ostringstream oss;
		oss << pNumber;
		return oss.str();
	}

	void ltrim(std::string &s);
	void rtrim(std::string &s);
	std::string &trim(std::string &s);
	std::string path(const std::string &path1, const std::string &path2);

	std::string getTime();
	std::string readFile(std::string path);

	std::string upperKebabCase(std::string str);
	std::string toUpper(std::string s);

} // namespace utils

#endif
