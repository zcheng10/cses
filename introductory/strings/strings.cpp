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

double N;

/** read file */
void read() {
	cin >> N;
}

/** search */
double search(double N) {
	if(N == 1){
		return 2;
	}
	return fmod(2*search(N - 1), pow(10, 9) + 7);
}

/*************/
int main() {
	read();
	double l = search(N);
	cout.precision(9);
	cout << l << endl;
}
