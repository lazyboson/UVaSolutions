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
        int t, n;
        in >> t;
        while (t--) {
            in >> n;
            vector<int> internal_difference; 
            int previous, input;
        	for(int i=0; i<n;i++) {
                in >> input;
        		if(i==0) {
                    previous = input;
        		}
        		else {
                    internal_difference.push_back(input - previous);
                    previous = input;
                }
        	}
    
            //processing the data
            int best = 0, worst = 0;
            int intermediate = 0;
            int current = internal_difference[0];
            if (current <= 2)
                worst = 1;
            else
                worst = 0;
        	//worst case
            for (int i = 1; i < internal_difference.size(); i++) {
                if (internal_difference[i] <= 2 && current <= 2) {
                    worst++;
                }
                else if (internal_difference[i] <= 2) {
                    intermediate = max(worst, intermediate);
                    worst = 1;

                }
                current = internal_difference[i];
            }
            worst = max(intermediate, worst) + 1;

        	//best case
            intermediate = 0;
            bool flag = false;
            current = internal_difference[0];
            if (current > 2)
                best = 1;
            else {
                 best = 2;
	            for(int i=1; i<internal_difference.size(); i++) {
		            if(internal_difference[i] <= 2 && current <=2) {
                        best++;
		            }
                    else if((internal_difference[i] > 2 && current <= 2)) {
                        if (intermediate == 0)
                            intermediate = best;
                        else 
                            intermediate = min(best, intermediate);
                        best = 1;
                    }
                    else if(internal_difference[i] <= 2 && current > 2) {
                        best++;
                    }
                    else if(internal_difference[i] > 2 && current >2 ) {
                    	//optimal found---best case
                        best = 1;
                        flag = true;
                        break;
                    }
                    current = internal_difference[i];
	            }
                if (intermediate != 0 && !flag)
                    best = min(intermediate, best);
            }

            out << best << " " << worst << endl;
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



