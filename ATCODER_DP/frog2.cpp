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
const int INF = 1e9 + 5;

class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int n,k;
        in >> n >> k;
        vector<int> height(n);
        for (auto &x : height)
            in >> x;
    	
		
        vector<int> dp(n, INF);
        dp[0] = 0;
    	for(int i=0; i<n; i++) {
            for (int j = i + 1; j <=i+k;j++) {
    			if(j<n) {
                    dp[j] = min(dp[j], abs(height[i] - height[j]) + dp[i]);
    			}
    		}
    	}
        out << dp[n - 1] << endl;
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



