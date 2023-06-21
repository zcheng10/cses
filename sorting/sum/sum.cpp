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

int n, x;

struct Values{
	int a;
	int pos;

	bool operator < (const Values& val) {
		return a < val.a;
	}
};

vector<Values> vec;

/** read file */
void read() {
	cin >> n >> x;
	vec.resize(n);
	for(int i = 0; i < n; i++){
		cin >> vec[i].a;
		vec[i].pos = i + 1;
	}
	sort(vec.begin(), vec.end());
}

/** search */
void search() {
	for(int i = 0; i < n; i++){
		int t = x - vec[i].a;
		if(t < x / 2){
			break;
		}
		int l = i+1;
		int h = n - 1;
		while(l <= h){
			int m = (l+h)/2;
			if(t > vec[m].a){
				l = m + 1;
			}
			if(t < vec[m].a){
				h = m - 1;
			}
			if(t == vec[m].a){
				cout << vec[i].pos << " " << vec[m].pos << endl;
				return;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

/*************/
int main() {
	read();
	search();

	//cout << endl;
}
