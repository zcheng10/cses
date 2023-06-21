#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>

// #include "C:/usaco/util/snipet.cpp"

using namespace std;

int N;

/** read file */
void read() {
	cin >> N;
}

/** search */
vector<string> search(int k) {
	vector<string> gry;
	gry.resize(pow(2, k));
	if(k == 1){
		gry[0] = "0";
		gry[1] = "1";
		return gry;
	}
	vector<string> l = search(k-1);
	vector<string> ans;
	ans.resize(0);
	for(int i=0; i < l.size(); i++)
    {
      string s=l[i];
      ans.push_back("0"+s);
    }
     
     // Append 1 to the second half
    for(int i=l.size()-1; i >= 0; i--)
    {
       string s=l[i];
       ans.push_back("1"+s);
    }
    return ans;
}

/*************/
int main() {
	read();
	vector<string> ans = search(N);


	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
}
