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


int N, k;
vector<int> num;

/** read file */
void read() {
	cin >> N >> k;
	num.reserve(N);
	num.resize(N);
	for (int i = 0; i < N; i++) {
		num[i] = i+1;
	}
}

/** search */
void search() {
	int p = k % num.size();
	for (int i = 0; i < N - 1; i++) {
		cout << num[p] << " ";
		num.erase(num.begin() + p);
		p = (p + k) % num.size();
	}
	cout << num[0];
}

/*************/
int main() {
	read();
	search();

	cout << endl;
}
