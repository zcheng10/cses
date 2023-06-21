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

int n, m;
ll k;
vector<ll> a, b;
int cnt = 0;

/** read file */
void read() {
	cin >> n >> m >> k;
	a.resize(n);
	b.resize(m);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int j = 0; j < m; j++){
		cin >> b[j];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}

/** search */
void search() {
	int i = 0;
	int j = 0;


	while (i < n && j < m){
		if (abs(a[i] - b[j]) <= k){
			i++; j++;
			cnt++;
		}
		else{
			if (a[i] - b[j] > k){
				j++;
			}
			else{
				i++;
			}
		}
	}
}

/*************/
int main() {
	read();
	search();
	
	cout << cnt << endl;
}
