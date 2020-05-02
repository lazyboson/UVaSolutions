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
    void solve(std::istream& in, std::ostream& out) {
        int t, n, q;
        in >> t;
        while (t--) {
            in >> n >> q;
            string s;
            in >> s;
            map<char, int> virus;
        	for(auto const& x:s) {
                virus[x]++;
        	}
        	while(q--) {
                int quaratine_centre;
                in >> quaratine_centre;
                int ans = 0;
        		for(auto const & v : virus) {
                    if (v.second > quaratine_centre)
                        ans += v.second - quaratine_centre;
        		}
                out << ans << endl;
        	}  
        }
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}

