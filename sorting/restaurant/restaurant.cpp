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
vector<int> a, b;

struct Event{
	int a;
	int t;

	bool operator < (const Event& e) const{
		return t < e.t;
	}
};



vector<Event> ev;

/** read file */
void read() {
	cin >> N;
	ev.resize(2*N);
	a.resize(N); b.resize(N);
	for(int i = 0; i < 2*N; i++){
		cin >> ev[i].t;
		ev[i].a = i % 2;
	}
	sort(ev.begin(), ev.end());
}

/** search */
int search() {
	int mx = 0;
	int ct = 0;
	for(int i = 0; i < 2*N; i++){
		if(ev[i].a == 0){
			ct++;
		}
		else{
			ct--;
		}
		mx = max(mx, ct);
	}
	return mx;
}

/*************/
int main() {
	read();
	int m = search();

	cout << m << endl;
}
