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

static const char dummy = '$';

class Solution {
public:
    void dfs(int i, vector<bool> &visited, bool &isAcron, bool &hasFound, const vector<int> adj[]) {
        visited[i] = true;
        for (auto u : adj[i]) {
            if (u == static_cast<int>(dummy)) {
                isAcron = true;
                return;
            }
            hasFound = true;
            if (visited[u] == false)
                dfs(u, visited, isAcron, hasFound, adj);
        }
    }

    vector<int> countTrees(const vector<int> adj[]) {
        vector<bool> visited(300, false);

        vector<int> ans;
        int cntTree = 0, cntAcron = 0;
        for (int i = 65; i < 91; i++) {
            bool isAcron = false;
            bool hasFound = false;
            if (visited[i] == false) {
                dfs(i, visited, isAcron, hasFound, adj);
                if (isAcron)
                    cntAcron++;
                if (hasFound)
                    cntTree++;
            }
        }
        ans.push_back(cntTree);
        ans.push_back(cntAcron);
        return ans;
    }

    void solve(std::istream &in, std::ostream &out) {
        int TC;
        in >> TC;
        static const string star = "*";
        int pos = 0;
        while (TC--) {
            vector<int> adj[300];
            string line;
            in.ignore();
            while (in >> line) {
                if (line.rfind(star) != string::npos)
                    break;
                //build a two directional graph
                int const forward = static_cast<int>(static_cast<unsigned char>(line[1]));
                int const backword = static_cast<int>(static_cast<unsigned char>(line[3]));
                adj[forward].push_back(backword);
                adj[backword].push_back(forward);
            }
            in >> line;
            for (auto &i : line) {
                if (i != ',') {
                    int const forward = static_cast<int>(static_cast<int>(i));
                    int const backword = static_cast<int>(dummy);
                    //push data in the adjacency list only if it has not been filled yet
                    if (adj[forward].empty())
                        adj[forward].push_back(backword);
                }
            }
            auto ans = countTrees(adj);

            out << "There are " << ans[0] << " tree(s) and " << ans[1] << " acorn(s)." << endl;
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
