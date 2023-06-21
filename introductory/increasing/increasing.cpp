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
vector<int> vec;
double cnt = 0;

/** read file */
void read() {
	cin >> N;
	vec.resize(N);
	for(int i = 0; i < N; i++){
		cin >> vec[i];
	}
}

/** search */
void search() {
	for(int i = 1; i < N; i++){
		if(vec[i] < vec[i - 1]){
			cnt += vec[i - 1] - vec[i];
			vec[i] = vec[i - 1];
		}
	}
}

/*************/
int main() {
	read();
	search();
	cout.precision(15);
	cout << cnt << endl;
}
