
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
int cnt = 0;
//int tot[4] = {9, 15, 12, 12};
int grd[9][9];

const int N = 48;
string dir;

/** read file */
void read() {
	cin >> dir;
	//cout << dir << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			grd[i][j] = 1;
		}
	}
	for (int i = 1; i < 8; i++) {
		for (int j = 1; j < 8; j++) {
			grd[i][j] = 0;
		}
	}
}

/** search */
void dfs(int x, int y, int k) {
	if(x == 1 && y == 1){
		if(k == 48){
			cnt++;
		}
		return;
	}
	if(k == 48){
		return;
	}

	if(grd[x][y] == 1){
		return;
	}
	if (grd[x - 1][y] == 1 && grd[x + 1][y] == 1 && grd[x][y + 1] == 0 && grd[x][y - 1] == 0) {
		return;
	}
	if (grd[x - 1][y] == 0 && grd[x + 1][y] == 0 && grd[x][y + 1] == 1 && grd[x][y - 1] == 1) {
		return;
	}
	//cout << x << " " << y << " " << k << endl;
	grd[x][y] = 1;
	if(dir[k] == '?'){
		dfs(x -1, y, k+1);
		dfs(x+1, y, k+1);
		dfs(x, y-1, k+1);
		dfs(x, y+1, k+1);
		grd[x][y] = 0;
		return;
	}
	switch(dir[k]){
	case 'U':
		dfs(x, y + 1, k + 1);
		break;
	case 'D':
		dfs(x, y - 1, k + 1);
		break;
	case 'L':
		dfs(x - 1, y, k + 1);
		break;
	case 'R':
		dfs(x + 1, y, k + 1);
		//default:
	}
	grd[x][y] = 0;
}

/*************/
int main() {
	read();
	dfs(1, 7, 0);
	cout << cnt << endl;
}
