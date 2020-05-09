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

bool is_lexical(string const &message) {
    char first = message[0];
    for (int i = 1; i < message.size(); i++) {
        if (message[i] <= first) {
            return true;
        }
        first = message[i];
    }
    return false;
}

class Solution {
public:
    void solve(std::istream &in, std::ostream &out) {

        //building the dictionary
        map<string, int> dictionary_mapper;
        int counter = 1;
        //first iteration
        for (int i = 97; i <= 122; i++) {
            stringstream ss;
            ss << char(i);
            dictionary_mapper[ss.str()] = counter;
            counter++;
        }

        //second iteration
        for (int i = 97; i <= 122; i++) {
            for (int j = i + 1; j <= 122; j++) {
                stringstream ss;
                ss << char(i) << char(j);
                dictionary_mapper[ss.str()] = counter;
                counter++;
            }
        }

        //third iteration
        for (int i = 97; i <= 122; i++) {
            for (int j = i + 1; j <= 122; j++) {
                for (int k = j + 1; k <= 122; k++) {
                    stringstream ss;
                    ss << char(i) << char(j) << char(k);
                    dictionary_mapper[ss.str()] = counter;
                    counter++;
                }
            }
        }

        //forth iteration
        for (int i = 97; i <= 122; i++) {
            for (int j = i + 1; j <= 122; j++) {
                for (int k = j + 1; k <= 122; k++) {
                    for (int l = k + 1; l <= 122; l++) {
                        stringstream ss;

                        ss << char(i) << char(j) << char(k) << char(l);
                        dictionary_mapper[ss.str()] = counter;
                        counter++;
                    }
                }
            }
        }

        //fifith iteration
        for (int i = 97; i <= 122; i++) {
            for (int j = i + 1; j <= 122; j++) {
                for (int k = j + 1; k <= 122; k++) {
                    for (int l = k + 1; l <= 122; l++) {
                        for (int m = l + 1; m <= 122; m++) {
                            stringstream ss;
                            ss << char(i) << char(j) << char(k) << char(l) << char(m);
                            dictionary_mapper[ss.str()] = counter;
                            counter++;
                        }
                    }
                }
            }
        }

        std::string word;
        while (in >> word) {
            bool lexical_status = is_lexical(word);
            if (lexical_status)
                out << 0 << endl;
            else {
                //lookup in dictionary
                auto ans = dictionary_mapper.find(word);
                if (ans != dictionary_mapper.end())
                    out << ans->second << endl;
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
