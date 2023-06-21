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

long long N;

/** read file */
void read() {
	cin >> N;
}

/** search */
void search() {
	cout << N;
	while(N != 1){
		if(N % 2 == 0){
			N = N/2;
		}
		else{
			N = 3*N+1;
		}
		cout << " " << N;
	}
}

/*************/
int main() {
	read();
	search();

	cout << endl;
}
