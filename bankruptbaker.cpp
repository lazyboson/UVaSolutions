#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)

class Solution {
public:
    void solve(std::istream &in, std::ostream &out) {
        int bakers;
        in >> bakers;
        while (bakers--) {
            multiset<pair<int, string>> ans;
            string baker_name;
            in.ignore();
            getline(in, baker_name);
            int m, n, b;
            in >> m >> n >> b;
            map<string, int> receipe_price;
            for (int i = 0; i < m; i++) {
                string current;
                int price;
                in >> current;
                in >> price;
                receipe_price.insert({current, price});
            }
            while (n--) {
                string dish;
                in.ignore();
                getline(in, dish);
                int ingradients;
                in >> ingradients;
                int sum = 0;
                while (ingradients--) {
                    string ingradient_name;
                    int ingradient_count;
                    in >> ingradient_name;
                    in >> ingradient_count;
                    auto const r = receipe_price.find(ingradient_name);
                    if (r != receipe_price.end()) {
                        sum += (r->second * ingradient_count);
                    }
                }
                if (sum <= b) {
                    ans.insert({sum, dish});
                }
            }

            //printing output as desired int the case
            transform(baker_name.begin(), baker_name.end(), baker_name.begin(), ::toupper);
            out << baker_name << endl;

            if (!ans.empty()) {
                for (auto const &m : ans) {
                    out << m.second << endl;
                }
            } else {
                out << "Too expensive!" << endl;
            }
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
