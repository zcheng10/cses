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

vector<pair<int, int>> in, out;
set<int> f;
vector<int> ans;

/** read file */
void read() {
	cin >> N;
	in.resize(N);
	out.resize(N);
	ans.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> in[i].first >> out[i].first;
		in[i].second = out[i].second = i;
		f.insert(i);
	} 
	sort(in.begin(), in.end());
	sort(out.begin(), out.end());
}

/** search */
void search() {
	int j = 0;
	for (int i = 0; i < N; i++) {
		while (j < N && out[j].first < in[i].first) {
			f.insert(ans[out[j].second]);
			j++;
		}
		ans[in[i].second] = *f.begin();
		f.erase(f.begin());
	}
	int k = *max_element(ans.begin(), ans.end()) + 1;
	cout << k << endl;
}

/*************/
int main() {
	read();
	search();
	for (int i = 0; i < N; i++) {
		cout << ans[i] + 1 << " ";
	}
}
