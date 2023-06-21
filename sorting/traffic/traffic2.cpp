#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdlib>

// #include "C:/usaco/util/snipet.cpp"

using namespace std;

int N, x;


/** read file */
void read() {

	cin >> x >> N;
	set<int> p = { 0, x };
	multiset<int> d = { x };
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		auto it = p.upper_bound(a);
		auto it2 = it;
		it2--;
		d.erase(d.find(*it - *it2));
		d.insert(a - *it2);
		d.insert(*it - a);
		p.insert(a);
		auto it1 = d.end();
		it1--;
		cout << *it1 << " ";
	}
}

/** search */


/*************/
int main() {
	read();
}
