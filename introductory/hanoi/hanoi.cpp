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
void dfs(int a, int b, int c, int k) {
	if(k == 0){
		cnt++;
		return;
	}
	dfs(a, c, b, k - 1);
	cout << a << ' ' << c << endl;
	dfs(b, a, c, k-1);
}

/*************/
int main() {
	read();
	

	cout << pow(2, N) - 1 << endl;
	dfs(1, 2, 3, N);
}
