#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)


class Solution {
public:	
	long long knap_sack(long long W, long long n, const vector<long long>& is, const vector<long long>& value, vector<vector<long long>> &dp) {
		//base condition
        if (n < 0)
            return 0;
		//if the value has been visited in the recursion tree---simply return it
        if (dp[n][W] != -1)
            return dp[n][W];

		//item weight is more than the current available weight---not possible to store leave this item
		if(is[n] > W) {
            dp[n][W] = knap_sack(W, n - 1, is, value, dp);
            return dp[n][W];
		}
		dp[n][W] = max(knap_sack(W - is[n], n - 1, is, value, dp) + value[n], knap_sack(W, n - 1, is, value, dp));
		return dp[n][W];
	}

    void solve(std::istream& in, std::ostream& out) {
        long long n, W;
        in >> n >> W;
        vector<long long> w(n), value(n);
    	for (int i=0;i<n;i++) {
            in >> w[i] >> value[i];
    	}
        vector<vector<long long>> dp(n + 1, vector<long long>(W + 1, -1));
        long long ans = knap_sack(W, n-1, w, value,dp);
        out << ans << endl;
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}


#include <fstream>
#include <iostream>


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}



