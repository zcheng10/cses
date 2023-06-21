#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>

// #include "C:/usaco/util/snipet.cpp"

using namespace std;

int N;
int cnt = 0;

/** read file */
void read() {
	cin >> N;
}

/** search */
void search() {
	for(int i = 1; pow(5, i) <= N; i++){
		cnt += N/pow(5, i);
	}
}

/*************/
int main() {
	read();
	search();

	cout << cnt <<  endl;
}
