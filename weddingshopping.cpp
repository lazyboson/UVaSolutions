#include <algorithm>
#include <iomanip>
#include <iostream>
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
const int N_INF = -1e9 + 5;

class Solution {
public:
    int M;
	int maximum_money(int money, int g, int category, const vector<vector<int>>& brand_price,  vector<vector<int>>& dp) {
        if (money < 0)
            return N_INF;
		//no more category are available and we have counted the money 
        if (category == g)
            return M - money;
        if (dp[money][g] != -1)
            return dp[money][g];
        int ans = -1;
        for (int model = 1; model <= brand_price[g][0]; model++) {
            int a = maximum_money(money - brand_price[g][model], g + 1, category, brand_price, dp);
            ans = max(ans, a);
            cout << ans << "and the value in current state   " << a << endl;
        }
        dp[money][g] = ans;
        return dp[money][g];
	}

    void solve(std::istream& in, std::ostream& out) {
        int TC, category;
        in >> TC;
        while (TC--) {
            in >> M >> category;
            vector<vector<int>> brand_price(25, vector<int>(25));
            vector<vector<int>> dp(210, vector<int>(25, -1));
        	for(int i=0; i<category; i++) {
        		//number of brand for that category
                in >> brand_price[i][0];
        		//price of each brand for this category
                for (int j = 1; j <= brand_price[i][0]; j++)
                    in >> brand_price[i][j];
        	}
            
            const int ans = maximum_money(M, 0, category, brand_price, dp);
            if (ans < 0)
                out << "no solution" << endl;
            else
                out << ans << endl;
        }
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}


#include <fstream>


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}



