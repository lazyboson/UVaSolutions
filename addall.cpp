#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
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
        int n;
        while (in >> n, n) {
            priority_queue<int, vector<int>, greater<int>> heap;

            while (n--) {
                int x;
                in >> x;
                heap.push(x);
            }
            int total = 0, cost = 0;
            while (heap.size() > 1) {
                total = heap.top();
                heap.pop();
                total += heap.top();
                heap.pop();
                cost += total;
                heap.push(total);
            }

            out << cost << endl;
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
