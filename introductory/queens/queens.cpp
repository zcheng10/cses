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

const int N = 8;
char chb[N][N];
int S[N];
int cnt = 0;


/** read file */
void read() {
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> chb[i][j];
		}
	}
}

/** search */
void dfs(int k) {
	if(k == N){
		cnt++;
		return;
	}
	for(int i = 0; i < N; i++){
		bool ok = true;
		
		for(int j = 0; j < k; j++){
			if(S[j] == i || abs(i - S[j]) == abs(k - j)){
				ok = false; break;
			}
		}

		if(chb[k][i] == '*'){
			ok = 0;
		}
		if(ok){
			S[k] = i;
			dfs(k+1);
		}
	}
}

/*************/
int main() {
	read();
	dfs(0);

	cout << cnt << endl;
}
