#include "LCS.h"

#include <algorithm>
#include <iostream>


void LCS::findLCS()
{
	const int f_len =first.size();
	const int s_len = second.size();

	//setting up the all elements of first row and first column in the second table to zero
	for (auto i = 0; i <= f_len; i++)
		second_table[i][0] = 0;
	for (auto i = 0; i <= s_len; i++)
		second_table[0][i] = 0;
	
	for(auto i=1; i<=f_len; i++)
	{
		for(auto j=1;j<=s_len; j++)
		{
			if(first[i] == second[j])
			{
				second_table[i][j] = second_table[i - 1][j - 1] + 1;
				first_table[i][j] = tildLeftArraow; 
			}
			else if(second_table[i-1][j] >= second_table[i][j-1])
			{
				second_table[i][j] = second_table[i - 1][j];  
				first_table[i][j] = upArrow; 
			}
			else
			{
				second_table[i][j] = second_table[i][j - 1];
				first_table[i][j] = leftArrow;  
			}
		}
	}
	std::cout << second_table[7][6]<< std::endl;
	printLCS(first, f_len, s_len);
}



void LCS::printLCS(std::string first, int f_len, int s_len)
{
	if(f_len == 0 || s_len==0)
	{
		return;
	}
	if(first_table[f_len][s_len] == tildLeftArraow)
	{
		printLCS(first, f_len - 1, s_len - 1);
		std::cout << first[f_len];
	}
	else if(first_table[f_len][s_len] == upArrow)
	{
		printLCS(first, f_len - 1, s_len);
	}
	else
	{
		printLCS(first, f_len, s_len - 1);
	}
}

//RECURSIVE VERSION
int LCS::alternate_LCS(int len1, int len2)
{
	if (len1 == 0 or len2 == 0)
		return 0;
	std::pair<int, int> my_state = { len1, len2 };
	auto const it = answer.find(my_state);
	if(it != answer.end())
	{
		return it->second;
	}
	if (first[len1 - 1] == second[len2 - 1])
		return answer[my_state] = 1 + alternate_LCS(len1 - 1, len2 - 1);
	return answer[my_state] = std::max(alternate_LCS(len1 - 1, len2), alternate_LCS(len1, len2 - 1));
}
