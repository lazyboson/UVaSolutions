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
        int TC, battlefield, green_warrior, blue_warrior;
        in >> TC;
        int input;
        while (TC--) {
            in >> battlefield >> green_warrior >> blue_warrior;
            //multiset with descending order
            multiset<int, greater<int>> gw_power, bw_power;
            for (int i = 0; i < green_warrior; i++) {
                in >> input;
                gw_power.insert(input);
            }

            for (int i = 0; i < blue_warrior; i++) {
                in >> input;
                bw_power.insert(input);
            }
            bool keepFlight = true;
            while (keepFlight) {
                int currentsize = min(gw_power.size(), bw_power.size());
                if (currentsize == 0)
                    keepFlight = false;
                if (currentsize > battlefield)
                    currentsize = battlefield;
                auto g = gw_power.begin();
                auto b = bw_power.begin();
                vector<int> g_change;
                vector<int> b_change;
                while (currentsize--) {
                    if (*g > *b) {
                        int change = *g - *b;
                        g_change.push_back(change);
                        auto g_next = g;
                        auto b_next = b;
                        ++g_next;
                        ++b_next;
                        gw_power.erase(g);
                        bw_power.erase(b);
                        g = g_next;
                        b = b_next;
                    } else if (*g < *b) {
                        int change = *b - *g;
                        b_change.push_back(change);
                        auto g_next = g;
                        auto b_next = b;
                        ++g_next;
                        ++b_next;
                        gw_power.erase(g);
                        bw_power.erase(b);
                        g = g_next;
                        b = b_next;
                    } else {
                        auto g_next = g;
                        auto b_next = b;
                        ++g_next;
                        ++b_next;
                        gw_power.erase(g);
                        bw_power.erase(b);
                        g = g_next;
                        b = b_next;
                    }
                }
                //reinsert and go for next round
                for (auto const &v : g_change)
                    gw_power.insert(v);
                for (auto const &v : b_change)
                    bw_power.insert(v);

                if (gw_power.empty() || bw_power.empty())
                    keepFlight = false;
            }

            if (gw_power.empty() && bw_power.empty())
                out << "green and blue died" << endl;
            else if (!gw_power.empty()) {
                out << "green wins" << endl;
                for (auto const &c : gw_power)
                    out << c << endl;
            } else if (!bw_power.empty()) {
                out << "blue wins" << endl;
                for (auto const &c : bw_power)
                    out << c << endl;
            }
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
