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

/** read file */
void read() {
	cin >> N;
}

/** search */
void search() {
	if(N <= 3){
		if(N == 1){
			cout << N;
		}
		cout << "NO SOLUTION";
	}
	else{
		for(int j = 2; j <= N; j+= 2){
			cout << j << " ";
		}
		for(int i = 1; i <= N; i+=2){
			cout << i << " ";
		}
	}
	cout << endl;
}

/*************/
int main() {
	read();
	search();
}
