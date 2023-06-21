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
set<int> st;

/** read file */
void read() {
	cin >> N;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		st.insert(a);
	}
}

/** search */
void search() {

}

/*************/
int main() {
	read();
	search();

	cout << st.size() << endl;
}
