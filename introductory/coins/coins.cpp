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

int N, a, b;

void search(int a, int b) {
	if((a+b) % 3 == 0){
		if(max(a, b) <= 2*min(a, b)){
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	return;
}

/** read file */
void read() {
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		search(a, b);
	}
}

/** search */


/*************/
int main() {
	read();
	//search();

	//cout << endl;
}
