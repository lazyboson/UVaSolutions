#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)


class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int n;
        in >> n;
        vector<long long> money(n);
    	for (int i=0; i<n;i++) {
            in >> money[i];
    	}
        long long  k = 1;
        long long o = 0;
    	for(int i=1; i<n; i++) {
            if (money[i - 1] <= money[i])
                k++;
            else
                o = max(o, k), k = 1;
    	}
        o = max(o, k);

        out << o << endl;
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



