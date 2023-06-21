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
vector<ll> p;
int cnt = 0;

int N;
ll x;

/** read file */
void read() {
	cin >> N >> x;
	p.resize(N);
	for(int i = 0; i < N; i++){
		cin >> p[i];
	}
	sort(p.begin(), p.end());
}

/** search, a: 1st; k: last */
void rec(ll *a, ll *k) {
	if(a == k){
		cnt++;
		return;
	}
	if(a > k){
		return;
	}
	if((*k) + (*a) <= x){
		cnt++;
		rec(a +1 , k-1);
	}
	if((*k) + (*a) > x){
		cnt++;
		rec(a, k - 1);
	}
}

/** search, a: 1st; k: last */
void search(int a, int k) {
	if(a == k){
		cnt++;
		return;
	}
	if(a > k){
		return;
	}
	if(p[k] + p[a] <= x){
		cnt++;
		search(a +1 , k-1);
	}
	if(p[k] + p[a] > x){
		cnt++;
		search(a, k - 1);
	}
}

/*************/
int main() {
	read();
	ll *a = p.data();
	ll *k = p.data() + p.size() - 1;
	// search(0, p.size() - 1);
	rec(a, k);

	cout << cnt << endl;
}
