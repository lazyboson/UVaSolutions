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
        while (TC--) {
            int category;
            in >> category;
            vector<int> category_threshold;
            map<string, vector<string>> category_keywords;
            while (category--) {
                string current_category_name;
                int W, R;
                in >> current_category_name >> W >> R;
                category_threshold.push_back(R);
                for (int i = 0; i < W; i++) {
                    string keyword;
                    in >> keyword;
                    category_keywords[current_category_name].push_back(keyword);
                }
            }
            string line;
            vector<string> ans;
            string sentence;
            in.ignore();
            while (getline(in, line) && !line.empty()) {
                sentence += line;
                sentence += " ";
            }

            //start processing on each category
            int cnt = 0;
            int ptr = 0;
            for (auto const &a : category_keywords) {
                istringstream iss(sentence);
                string current;
                while (iss >> current && cnt < category_threshold[ptr]) {
                    //if current string have dot remove it from end since it can be at last place ony as per problem
                    if (find(current.begin(), current.end(), '.') != current.end())
                        current.pop_back();

                    if (find(a.second.begin(), a.second.end(), current) != a.second.end()) {
                        cnt++;
                    }
                }
                if (cnt == category_threshold[ptr])
                    ans.push_back(a.first);
                //reset the count for new round
                ptr++;
                cnt = 0;
            }
            int present = 0;
            //printing in fancy style as required
            if(ans.size())
                out << "‘SQF Problem.";
            for (auto const &v : ans) {
                out << v;
                present++;
                if (present > 0 && present < ans.size())
                    out << ",";
            }
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
