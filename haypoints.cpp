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
        int n, m;
        in >> n >> m;
        map<string, int> hay_points;
        while (n--) {
            string word;
            int points;
            in >> word >> points;
            hay_points.insert({word, points});
        }
        while (m--) {
            string line;
            long long ans = 0;
            while (getline(in, line) && line != ".") {
                istringstream iss(line);
                string current;
                while (iss >> current) {
                    for (auto const &h : hay_points) {
                        auto match = hay_points.find(current);
                        //if match has been found just add value and leave the string
                        if (match != hay_points.end()) {
                            ans += static_cast<long long>(match->second);
                            break;
                        }
                    }
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
