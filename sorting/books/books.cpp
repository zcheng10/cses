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
vector<int> t;


/** read file */
void read() {
	cin >> N;
	t.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}
	sort(t.begin(), t.end());
}

/** search */
void search() {
	ll s1 = 0;
	for (int i = 0; i < N - 1; i++) {
		s1 += t[i];
	}
	if (s1 <= t[N - 1]) {
		cout << 2 * t[N - 1];
	}
	else {
		cout << (s1 + t[N-1]);
	}
}

/*************/
int main() {
	read();
	search();

	cout << endl;
}
