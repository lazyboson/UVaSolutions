// test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include<set>
using namespace std;


int main()
{
	vector<pair<int, int>> duplicates;
	int num;
	bool isFound = false;
	while(cin>>num)
	{
		isFound = false;
		for(int i=0; i<duplicates.size(); i++)
		{
			if(duplicates[i].first == num)
			{
				duplicates[i].second += 1;
				isFound = true;
				break;
			}
		}
		if (!isFound)
			duplicates.push_back(make_pair(num, 1));
	}
	for (auto x : duplicates)
		cout << x.first << " " << x.second << endl;
	return 0;
}


