// DP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Equation for the rod-cutting is r_n =  for (1 to n) max_(p_i + r_(n-1))

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using  namespace std;


void printRodCutSolution(vector<int>& a, int length)
{
	while (length > 0)
	{
		cout << a[length] << endl;
		length -= a[length];
	}
}

//bottom-up dp
void rodCuttingBottomUp(std::vector<int> &price, int length)
{
	vector<int> r(length+1,-1), s(length+1,-1);
	r[0] = 0;
	for(int j=1; j<=length;j++)
	{
		int q = -99;
		for(int i = 1; i<=j;i++)
		{
			if(q <price[i] +r[j-i])
			{
				q = price[i] + r[j - i];
				s[j] = i;
			}		
		}
		r[j] = q;
	}
	printRodCutSolution(s, length);
}


//top-down dp
int memoizedRodCutting(std::vector<int> &price, int* dp, int length)
{
	int q;
	if (dp[length] >= 0)
		return dp[length];
	if (length == 0)
		q = 0;
	else
	{
		q = -1;
		for (int i = 1; i <= length; i++)
			q = std::max(q, price[i] + memoizedRodCutting(price, dp, length - i));
	}

	dp[length] = q;
	return q;
}

//very bad exponential solution
int rodCutting(std::vector<int>& price, int length)
{
	//base case
	if (length == 0)
		return 0;
	int ans = -1;
	for (int i = 1; i <= length; i++)
		ans = std::max(ans, price[i] + rodCutting(price, length - i));
	return ans;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	//initialize dp with all negatice value
	int dp[100];
	memset(dp, -1, sizeof(dp[0]));
	int l, re;
	std::cin >> l;
	std::vector<int> price(l+1);
	//using one based index scaping number zero
	for(int i=1; i<=l;i++)
	{
		std::cin >> price[i];
	}
	std::cout << "the length which you want to cut" << std::endl;
	std::cin >> re;
	int res = memoizedRodCutting(price,dp,re);
	//rodCuttingBottomUp(price, re);
	std::cout << res << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

