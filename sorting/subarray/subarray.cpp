
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
using ll = long long;

int N;
vector<ll> x;
vector<ll> a;

/** read file */
void read() {
	cin >> N;
	x.resize(N);
	a.resize(N);
	for(int i = 0; i < N; i++){
		cin >> x[i];
	}
}

/** search */
ll search() {
	a[0] = x[0];
	for(int i = 1; i < N; i++){
		a[i] = a[i - 1] + x[i];

	}
	ll mn = 1e9;
	ll mx = -1e9;

	ll k = a[0];
	mn = min(a[0], (ll) 0);
	mx = k;
	for(int j = 1; j < N; j++){
		k = a[j] - mn;
		mn = min(a[j], mn);
		mn = min(mn, (ll) 0);
		mx = max(mx, k);
		//cout << mn <<  " " << mx << endl;
	}
	return mx;
}

/*************/
int main() {
	read();
	ll mx = search();

	cout << mx << endl;
}
