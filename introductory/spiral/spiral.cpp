#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

// #include "C:/usaco/util/snipet.cpp"

using namespace std;
using ll = long long;

ll t, y, x;

ll search(ll y, ll x) {
	ll k = max(y, x);
	if(k == x){
		if(k % 2 == 0){
			return (x - 1)*(x - 1) + y;
		}
		else{
			return k*k - y + 1;
		}
	}
	if(k % 2 == 1){
		return (y - 1)*(y - 1) + x;
	}
	else{
		return k*k - x + 1;
	}
}

//vector<Pair> vec;
/** read file */
void read() {
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> y >> x;
		long long k = search(y, x);
		cout.precision(19);
		cout << k << endl;
	}
}

/** search */

/*************/
int main() {
	read();

	//cout << endl;
}
