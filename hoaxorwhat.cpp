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
    void solve(std::istream &in, std::ostream &out) {
        int days;
        while (in >> days && days != 0) {
            multiset<int> price_slip;
            long long ans = 0;
            while (days--) {
                int k;
                in >> k;
                for (int i = 0; i < k; i++) {
                    int input;
                    in >> input;
                    price_slip.insert(input);
                }

                multiset<int>::iterator min_price;
                multiset<int>::reverse_iterator max_price;
                if (!price_slip.empty())
                    max_price = price_slip.rbegin();
                if (!price_slip.empty())
                    min_price = price_slip.begin();

                if (max_price != price_slip.rend() && min_price != price_slip.end()) {
                    ans += static_cast<long long>(*max_price) - static_cast<long long>(*min_price);
                    price_slip.erase(next(max_price).base());
                    price_slip.erase(min_price);
                }
            }
            out << ans << endl;
        }
    }
};

void solve(std::istream &in, std::ostream &out) {
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}

#include <fstream>
#include <iostream>

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    istream &in = cin;

    ostream &out = cout;

    solve(in, out);
    return 0;
}
