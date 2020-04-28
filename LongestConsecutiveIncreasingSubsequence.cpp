#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)


class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int n;
        in >> n;
        vector<long long> money(n);
    	for (int i=0; i<n;i++) {
            in >> money[i];
    	}
    	//default subsequence shall be 1 in worst case
        vector<long long > dp(n + 1, 1);
       long long ans = LIS(money,dp, n);
       out << ans << endl;
    	
    }

	//longest consecutive sequence--> O(n^2) ---TLE 
    long long LIS(vector<long long >& money, vector<long long>& dp, int n) {
        long long last_max = 0;
        long ans = 0;
        for (int i = 1; i < n; i++) {
            if (money[i - 1] <= money[i]) {
                dp[i] = dp[i - 1] + 1;
                if (ans < dp[i])
                    ans = dp[i];
                last_max = i;
            }
            else {
                for (int j = i - 1; j >= last_max; j--) {
                    if (money[j] > money[i]) {
                        continue;
                    }
                    long long possibleAns = dp[j] + 1;
                    if (possibleAns > dp[i]) {
                        dp[i] = possibleAns;
                        if (dp[i] > ans)
                            ans = dp[i];
                    }
                }
            }
        }
        return ans;
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



