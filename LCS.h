#pragma once
#include <map>
#include <string>
#include <vector>

class LCS
{
	std::string first, second;
	std::vector<std::vector<int>> first_table, second_table;
	std::map<std::pair<int, int>, int> answer;
	 char upArrow = '@';
	 char leftArrow = '*';
	 char tildLeftArraow = '~';
public:
	//constructor
	LCS(std::string& __first, std::string& __second)
	{
		first = __first;
		second = __second;
		first_table.resize(__first.size()+1, std::vector<int>(__second.size()+1));
		second_table.resize(__first.size() + 1, std::vector<int>(__second.size() + 1));
	}
	void findLCS();
	void printLCS(std::string first, int f_len, int s_len);

	int alternate_LCS(int len1, int len2);

};

