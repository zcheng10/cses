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

int N, x;
vector<pair<int, int>> v;

/** read file */
void read() {
	cin >> N >> x;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end());
}

/** search */
void search() {
	
}

/*************/
int main() {
	read();
	search();

	cout << endl;
}
