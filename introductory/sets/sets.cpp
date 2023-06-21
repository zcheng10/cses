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

int n;

/** read file */
void read() {
	cin >> n;
}

/** search */
void search() {
	if((n % 4 == 1) || (n % 4 == 2)){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	if(n % 4 == 0){
		cout << n/2 << endl;
		for(int i = 1; i <= n-3; i+=4){
			cout << i << " " << i+3 << " ";
		}
		cout << endl << n/2 << endl;
		for(int j = 2; j <= n-2; j+=4){
			cout << j << " " << j+1 << " ";
		}
		return;
	}
	cout << (n - 3)/2 + 2 << endl;
	cout << "1 2 ";
	for(int k = 4; k <= n-3; k+=4){
		cout << k << " " << k+3 << " ";
	}
	cout << endl << (n-3)/2 + 1 << endl;
	cout << "3 ";
	for(int l = 5; l <= n-2; l+=4){
		cout << l << " " << l+1 << " ";
	}
	return;
}

/*************/
int main() {
	read();
	search();

	//cout << endl;
}
