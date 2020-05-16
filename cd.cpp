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
        int n, m;
        while (in >> n && in>>m && n!=0 && m!=0) {
            set<int> first_cd;
        	for (int i=0; i<n; i++) {
                int input;
                in >> input;
                first_cd.insert(input);
        	}
            int ans = 0;
        	for (int i=0; i<m; i++) {
                int input;
                in >> input;
                if (first_cd.find(input) != first_cd.end())
                    ans++;
        	}
            out << ans << endl;
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


