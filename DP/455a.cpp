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
        std::map<int, int> cnt;
        vector<long long> dp(111111, 0);
        vector<pair<int, int>> v;
        int n;
        in >> n;
        for (int i = 0; i < n; i++) {
            int input;
            in >> input;
            cnt[input]++;
        }
        for (auto x : cnt)
            v.emplace_back(make_pair(x.first, x.second));
        for (int i = 0; i < (int)v.size(); i++) {
            int ptr = i - 1;
            while (ptr >= 0 && v[ptr].first + 1 == v[i].first) {
                ptr--;
            }
            if (ptr == -1) {
                dp[i] = 1LL * v[i].first * v[i].second;
            }
            else {
                dp[i] = dp[ptr] + 1LL * v[i].first * v[i].second;
            }
            if (i != 0)
                dp[i] = max(dp[i], dp[i - 1]);
        }
        out << dp[(int)v.size() - 1] << endl;
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



