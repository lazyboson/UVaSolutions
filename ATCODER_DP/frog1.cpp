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
        int n;
        in >> n;
        vector<int> height(n);
        for (auto &x : height)
            in >> x;
    	
		
        vector<int> dp(n, INF);
        dp[0] = 0;
    	for(int i=0; i<n; i++) {
    		for(int j:{i+1, i+2}) {
    			if(j<n) {
                    dp[j] = min(dp[j], abs(height[i] - height[j]) + dp[i]);
    			}
    		}
    	}

        out << dp[n - 1] << endl;

    	//base case -- as per given problema
    	// if(n==2) {
     //        dp[1] = abs(height[1] - height[0]);
     //        out << dp[1] << std::endl;
     //        return;
    	// }
    	// //initializing dp[2] here
     //    dp[1] = abs(height[1] - height[0]);
    	// for(int i=2;i<n;i++) {
     //        dp[i] = min(abs(height[i - 1] - height[i])+ dp[i-1], abs(height[i - 2] - height[i]) +dp[i-2]);
    	// }
     //    out << dp[n - 1] << endl;
     //    
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



