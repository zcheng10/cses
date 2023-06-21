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

struct Event {
	int t; // timen
	bool ar; // arrival, true; depart, false
	int id; // 1 ~ N

	bool operator < (const Event& e) const {
		if (t == e.t) {
			return ar;
		}
		return t < e.t;
	}

	void print() {
		cout << t << " " << ar << " " << id << endl;
	}
};

int N;

vector<Event> ev;
set<int> f; // free room
int cnt = 0;
vector<int> ans;

/** read file */
void read() {
	cin >> N;
	ev.resize(2 * N);
	ans.resize(N + 1);
	for (int i = 0; i < 2*N; i+= 2) {
		cin >> ev[i].t >> ev[i + 1].t;
		ev[i].ar = true;
		ev[i + 1].ar = false;
		ev[i].id = ev[i + 1].id = i / 2 + 1;
		f.insert(i/2 + 1);
	} 
	sort(ev.begin(), ev.end());
}

/** search */
void search() {
	for (int i = 0; i < 2 * N; i++) {
		if (ev[i].ar) {
			ans[ev[i].id] = *f.begin();
			f.erase(f.begin());
		}
		else {
			f.insert(ans[ev[i].id]);
		}
	}
}

/*************/
int main() {
	read();
	search();
	int k = *max_element(ans.begin(), ans.end());
	cout << k << endl;
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
}
