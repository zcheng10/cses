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

ll N;

/** read file */
void read() {
	cin >> N;
}

/** search */
ll search(ll k) {
	return k*k * (k*k - 1) / 2 - 4*(k - 2)*(k - 1);
}

/*************/
int main() {
	read();
	for(ll i = 1; i < N + 1; i++){
		ll cnt = search(i);
		cout << cnt << endl;
	}
}
