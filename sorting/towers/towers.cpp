#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <list>

// #include "C:/usaco/util/snipet.cpp"

using namespace std;

int N;
vector<int> k;
multiset<int> t;

/** read file */
void read() {
	cin >> N;
	k.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> k[i];
	}
}

/** search */
void search() {
	for (int i = 0; i < N; i++) {
		auto it = t.upper_bound(k[i]);

		if (it == t.end()) {
			t.insert(k[i]);
		}
		else {
			//cout << *it << endl;
			t.erase(it);
			t.insert(k[i]);

		}
		/*for (auto j : t) {
			cout << j << ", ";
		}
		cout << endl;*/
	}
}

/*************/
int main() {
	read();
	search();
	cout << t.size() << endl;
}
