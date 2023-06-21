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

// vector<char> dna;
int m = 1;
int M = 1;
string s;

/** read file */
void read() {
	cin >> s;
}

/** search */
void search() {
	char a = s[0];
	for(int i = 1; i < s.length(); i++){
		if(s[i] == a){
			m++;
		}
		else{
			a = s[i];
			M = max(M, m);
			m = 1;
		}
	}
	M = max(M, m);
}

/*************/
int main() {
	read();
	search();

	cout << M << endl;
}
