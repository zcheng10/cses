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

int N;
map<int, int> m;
vector<int> k;

/** read file */
void read() {
	cin >> N;
	k.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> k[i];
	}
	for (int j = N - 1; j >= 0; j--) {
		m[k[j]] = -1;
	}
	/*for (auto x : m) {
		cout << x.first << " " << x.second << endl;
	}*/
}

/** search */
int search() {
	int a = 0;
	int b = 0;
	int mx = 0;
	for (int i = 0; i < N; i++) {
		auto x = m.find(k[i]);
				if (x->second < a) {
					b++;
					if (i == N - 1) {
						mx = max(mx, b);
					}
					//cout << "a, b, x2 = " << a << " " << b << " " << x->second << endl;
				}
				else {
					a = x->second + 1;
					mx = max(mx, b);
					b = i - a + 1;
					//cout << "ka, b, x2 = " << a << " " << b << " " << x->second << endl;
				}
				m[x->first] = i;
	}
	return mx;
}

/*************/
int main() {
	read();

	cout << search() << endl;
}
