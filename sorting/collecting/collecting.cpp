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
vector<int> b;

/** read file */
void read() {
	cin >> N;
	b.resize(N);
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		b[a-1] = i;
	}
}

/** search */
int search() {
	/*for(int i = 0; i < N; i++){
		b[a[i]] = i;
	}*/
	int s = 1;
	for(int i = 1; i < N; i++){
		if(b[i] < b[i-1]){
			s++;
		}
	}
	return s;
}

/*************/
int main() {
	read();
	int s = search();

	cout << s << endl;
}
