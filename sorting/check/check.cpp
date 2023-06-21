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
vector<int> x, y, ans1, ans2;

/** read file */
void read() {
	cin >> N;
	x.resize(N);
	y.resize(N);
	ans1.resize(N);
	ans2.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
		ans1[i] = 0;
		ans2[i] = 0;
	}
}
// returns a if a contains b, b if b contains a, -1 if neither
int compare(int a, int b) {
	if (x[a] <= x[b] && y[a] >= y[b]) {
		return 1;
	}
	/* if (x[a] >= x[b] && y[a] <= y[b]) {
		return b;
	} */
	return 0;
}
/** search */
void search() {
	for (int i = 0; i < N; i++) {
		if (ans1[i] == 1 && ans2[i] == 1) {
			continue;
		}
		for (int j = i + 1; j < N; j++) {
			if (ans1[j] == 1 && ans2[j] == 1) {
				continue;
			}
			if (compare(i, j)) {
				ans1[i] = 1;
				ans2[j] = 1;
				continue;
			}
			if (compare(j, i)) {
				ans1[j] = 1;
				ans2[i] = 1;
			}
		}
	}

}

/*************/
int main() {
	read();
	search();
	for (int i = 0; i < N; i++) {
		cout << ans1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << ans2[i] << " ";
	}
	cout << endl;
}
