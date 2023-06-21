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

struct Task {
	int a;
	int d;

	bool operator < (Task t) {
		return a < t.a;
	}
};
int N;
vector<Task> v;

/** read file */
void read() {
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].a >> v[i].d;
	}
	sort(v.begin(), v.end());
}

ll s = 0;
ll ans = 0;
/** search */
void search() {
	for (int i = 0; i < N; i++) {
		s += v[i].a;
		ans += v[i].d - s;
	}
}

/*************/
int main() {
	read();
	search();

	cout << ans << endl;
}
