#include "LCS.h"

#include <algorithm>
#include <iostream>


void LCS::findLCS()
{
	int f_len =first.size();
	int s_len = second.size();

	//setting up the all elements of first row and first column in the second table to zero
	for (int i = 0; i <= f_len; i++)
		second_table[i][0] = 0;
	for (int i = 0; i <= s_len; i++)
		second_table[0][i] = 0;
	
	for(int i=1; i<=f_len; i++)
	{
		for(int j=1;j<=s_len; j++)
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
	printLCS(first, f_len, s_len);
}



void LCS::printLCS(std::string first, int f_len, int s_len)
{
	if(f_len == 0 or s_len==0)
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
