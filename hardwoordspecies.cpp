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
        int TC;
        in >> TC;
        string line;
        while (TC--) {
            //ignore the whitespace prior to input
            in.ignore();
            map<string, int> tree;
            long long count = 0;
            while (getline(in, line) && !line.empty()) {
                tree[line]++;
                count++;
            }

            //calculate percentage
            for (auto const &t : tree) {
                const double percentage = (static_cast<double>(t.second) / static_cast<double>(count)) * 100;
                out << t.first << " " << fixed << setprecision(4) << percentage << endl;
            }
            //place whitespace post each output except the last one
            if (TC)
                out << endl;
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
