#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinimumCoin
{
	vector<int> coins;
	int change;
	vector<int> dp;
public:
	explicit MinimumCoin(int __len__);

	MinimumCoin(vector<int>& __coins__, int __change__)
	{
		coins = __coins__;
		change = __change__;
	}

	//Recursive bad solution
	static int countMin(vector<int>& coins, int change);

	 int count_min_dp(vector<int>& coins, int change);
	
};

