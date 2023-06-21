#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

// #include "C:/usaco/util/snipet.cpp"

using namespace std;

int N, m;
vector<int> x, a, b, c;

/** read file */
void read() {
	cin >> N >> m;
	x.resize(N);
	c.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		x[i]--;
		c[x[i]] = i;
	}
	a.resize(m);
	b.resize(m);
	for (int j = 0; j < m; j++) {
		cin >> a[j] >> b[j];
		a[j]--;
		b[j]--;
	}
}

int compare(int a, int b) {
	if (b >= N) {
		return 0;
	}
	if (a < 0) {
		return 0;
	}
	return c[a] < c[b] ? 0 : 1;
}

int func(int xa, int xb) {
	int d1 = 0;
	if (xb < xa) {
		std::swap(xa, xb);
	}
	if (xa - xb == -1) {
		d1 += compare(xa, xa+1);
		d1 += compare(xa-1, xa);
		d1 += compare(xb, xb+1);
	}
	else {
		d1 += compare(xa - 1, xa);
		d1 += compare(xa, xa + 1);
		d1 += compare(xb, xb + 1);
		d1 += compare(xb - 1, xb);
	}
	return d1;
}

/** search */
void search() {
	int z = 1;
	for (int i = 1; i < N; i++) {
		if (c[i] < c[i - 1]) {
			z++;
		}
	}
	for (int i = 0; i < m; i++) {

		int d1 = func(x[a[i]], x[b[i]]);
		// a[i] <-> b[i]
		// x[a_i] <-> x[b_i]
		// c[x[ai]] <-> c[x[bi]]
		std::swap(x[a[i]], x[b[i]]);
		std:swap(c[x[a[i]]], c[x[b[i]]]);
		int d2 = func(x[a[i]], x[b[i]]);
		z += (d2 - d1);
		cout << z << endl;
	}
}

/*************/
int main() {
	read();
	search();

	//cout << endl;
}
