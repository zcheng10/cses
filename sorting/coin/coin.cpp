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

int N;
vector<ll> c;

/** read file */
void read() {
	cin >> N;
	c.resize(N);
	for(int i = 0; i < N; i++){
		cin >> c[i];
	}
}

/** search */
ll search() {
	sort(c.begin(), c.end());
	ll m;
	if(c[0] != 1){
		return 1;
	}
	m = c[0];
	for(int i = 0; i < N; i++){
		if(m < c[i]){
			return m;
		}
		m += c[i];
	}
	return m;
}

/*************/
int main() {
	read();
	ll ans = search();

	cout << ans << endl;
}
