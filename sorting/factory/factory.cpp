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

int N, t;
vector<ll> k;
double p = 0;

/** read file */
void read() {
	cin >> N >> t;
	k.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> k[i]; 
		p += 1.0 / k[i];
	}
	//cout << p << endl;
	sort(k.begin(), k.end());
}

/** search */
ll search() {
	ll l = t / p;
	int s = 0;
	for (int i = 0; i < N; i++) {
		s += l / k[i];
	}
		
	ll r = l + (t-s)*k[0];
	ll ans = 0;
	//cout << l << " " << r << endl;
	while (l <= r) {
		ll m = (l + r) / 2;
		ll x = 0;
		for (int i = 0; i < N; i++) {
			x += m / k[i];
		}
		if (x >= t) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
			continue;
		}
	}
	return ans;
}

/*************/
int main() {
	read();
	

	cout << search() << endl;
}
