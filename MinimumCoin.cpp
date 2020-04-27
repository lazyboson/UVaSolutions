#include "MinimumCoin.h"

MinimumCoin::MinimumCoin(int __len__): change(0) {
	//resize and fill default value to -1
	dp.resize(__len__, -1);
}

int MinimumCoin::countMin(vector<int>& coins, int change)
{
	if(change == 0) {
		return 0;
	}
	int min = INT_MAX;
	for(auto coin : coins) {
		
		if (change - coin >= 0) {
			int c = countMin(coins, change - coin);
			if (min > c + 1)
				min = c + 1;
		}
	}
	return min;	
}

int MinimumCoin::count_min_dp(vector<int>& coins, int change) {
	if (change == 0) {
		return 0;
	}
	int min = INT_MAX;
	for (auto coin : coins) {

		if (change - coin >= 0) {
			int c;
			if (dp[change - coin] >= 0)
				c = dp[change - coin];
			else {
				c = countMin(coins, change - coin);
				dp[change - coin] = c;
			}
			if (min > c + 1)
				min = c + 1;
		}
	}
	return min;
}
