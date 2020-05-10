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
        map<string, string> data;
        string line;
        while (getline(in,line) && !line.empty()) {
            istringstream iss(line);
            string english_word, foreign_language_word;
            iss >> english_word >> foreign_language_word;
            data.insert(pair<string,string> (foreign_language_word,english_word));
        }

        while (getline(in, line) && !line.empty()) {
            auto const matcher = data.find(line);
            if (matcher != data.end())
                out << matcher->second << endl;
            else
                out << "eh" << endl;
        }
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


