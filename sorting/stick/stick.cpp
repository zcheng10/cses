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
vector<ll> p;
ll sum = 0;

/** read file */
void read() {
	cin >> N;
	p.resize(N);
	for(int i = 0; i < N; i++){
		cin >> p[i];
		sum += p[i];
	}
}

/** search */
ll search() {
	sort(p.begin(), p.end());
	ll med = p[N/2];
	ll ans = 0;
	for(int i = 0; i < N; i++){
		ans += abs(p[i] - med);
	}
	return ans;
}

/*************/
int main() {
	read();
	ll a = search();

	cout << a << endl;
}
