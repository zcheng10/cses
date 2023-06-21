#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

// #include "C:/usaco/util/snipet.cpp"

using namespace std;

int n, m;
multiset<int> tickets;
vector<int> h;

/** read file */
void read() {
	cin >> n >> m;
	h.resize(m);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		tickets.insert(x);
	}
	for (int j = 0; j < m; j++) {
		cin >> h[j];
	}
}

/** search */
void search() {
	for (int i = 0; i < m; i++) {
		auto it = tickets.upper_bound(h[i]);
		if (it == tickets.begin()) {
			cout << -1 << endl;
		}
		else {
			cout << *(--it) << endl;
			tickets.erase(it);
		}
	}
}

/*************/
int main() {
	read();
	search();

	//cout << endl;
}