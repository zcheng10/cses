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

double N;
double S;
int m = 0;

/** read file */
void read() {
	cin >> N;
	S = N*(N+1)/2;
	//cout << S << endl;
	for(double i = 0; i < N - 1; i++){
		double k;
		cin >> k;
		S -= k;
	}
}

/** search */
void search() {
	
}

/*************/
int main() {
	read();
	search();

	cout << S << endl;
}
