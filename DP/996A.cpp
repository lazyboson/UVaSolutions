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
typedef long long ll;
// Powered by caide (code generator, tester, and library code inliner)


class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        ll ans = 0;
        ll money;
        in >> money;
    	if(money >= 100LL) {
                ans += money / 100LL;
            	//remaining money
                money %= 100LL;
    	}
    	if(money >= 20LL) {
          
                ans += money / 20LL;
                //remaining money
                money %= 20LL;
    	}
    	if (money >= 10LL) {
           
                ans += money / 10LL;
                //remaining money
                money %= 10LL;
            
        }
        if (money >= 5LL) {
           
                ans += money / 5LL;
                //remaining money
                money %= 5LL;
            
        }
        if (money >= 1LL) {
            ans += money;
        }
        out << ans;
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



