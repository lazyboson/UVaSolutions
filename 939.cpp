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
#include <utility>
#include <vector>

#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)

#define rep(i, n) REP(i, 0, n)

// Powered by caide (code generator, tester, and library code inliner)

using namespace std;

map<string, string> persons;
map<string, vector<string>> parents;

class Solution {
public:
    static void resolve(string child, string parent1, string parent2) {
        if (persons.find(parent1) == persons.end()) {
            resolve(parent1, parents[parent1][0], parents[parent1][1]);
        }

        if (persons.find(parent2) == persons.end()) {
            resolve(parent2, parents[parent2][0], parents[parent2][1]);
        }

        bool has_gene = false;

        if (persons[parent1] != "non-existent" && persons[parent2] != "non-existent") {
            has_gene = true;
        } else if (persons[parent1] == "dominant" || persons[parent2] == "dominant") {
            has_gene = true;
        }

        if (has_gene) {
            if (persons[parent1] == "dominant" && persons[parent2] == "dominant") {
                persons[child] = "dominant";
            } else if (persons[parent1] == "dominant" && persons[parent2] == "recessive") {
                persons[child] = "dominant";
            } else if (persons[parent1] == "recessive" && persons[parent2] == "dominant") {
                persons[child] = "dominant";
            } else {
                persons[child] = "recessive";
            }
        } else {
            persons[child] = "non-existent";
        }
    }

    static bool theTruthIsOutThere(const pair<string, string> &a, const pair<string, string> &b) {
        return a.first < b.first;
    }
    void solve(std::istream &in, std::ostream &out) {

        int n;
        string a, b;
        vector<pair<string, string>> result;

        in >> n;

        while (n--) {
            in >> a >> b;

            if (b == "non-existent" || b == "recessive" || b == "dominant") {
                persons[a] = b;
            } else {
                parents[b].push_back(a);
            }
        }

        for (map<string, vector<string>>::iterator it = parents.begin(); it != parents.end(); it++) {
            resolve(it->first, (it->second)[0], (it->second)[1]);
        }

        for (map<string, string>::iterator it = persons.begin(); it != persons.end(); it++) {
            result.push_back(make_pair(it->first, it->second));
        }

        sort(result.begin(), result.end(), theTruthIsOutThere);

        rep(i, sz(result)) {
            out << result[i].first << " " << result[i].second << endl;
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
