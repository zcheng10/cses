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


int N, k;
set<int> num;

/** read file */
void read() {
	cin >> N >> k;
	for (int i = 0; i < N; i++) {
		num.insert(i + 1);
	}
}

/** search */
void search() {
	int p = k % num.size();
	auto it = num.begin();
	advance(it, p);
	for (int i = 0; i < N - 1; i++) {
		cout << *it << " ";
		auto i2 = next(it);
		num.erase(it);
		//i2++;
		it = i2;
		if (it == num.end()) {
			it = num.begin();
		}
		//cout << p << " ";
		int q = (p + k) % num.size();
		//cout << "q = " << q << endl;
		if (q < p) {
			it = num.begin();
			advance(it, q);
		}
		else {
			advance(it, q - p);
		}
		p = q;
	}
	cout << *it;
}

/*************/
int main() {
	read();
	search();

	cout << endl;
}