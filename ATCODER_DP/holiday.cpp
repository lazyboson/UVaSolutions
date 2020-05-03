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
        vector<int> dp(3);
    	for(int day=0; day<n;day++) {
            vector<int> new_dp(3, 0);
    		//input
            vector<int> c(3);
    		for(int i=0; i<3; i++) {
                in >> c[i];
    		}
    		//process
    		for(int i=0; i<3;i++) {
    			for(int j=0; j<3; j++) {
    				if(i!=j) {
                        new_dp[j] = max(new_dp[j], dp[i] + c[j]);
    				}
    			}
    		}
            dp = new_dp;
    	}
        out << max({ dp[0],dp[1],dp[2] });
    	
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}

