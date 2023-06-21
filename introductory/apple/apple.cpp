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
using ll = long long;

int N;
vector<ll> p;
ll sum = 0;
double m = 20*pow(10, 9);
vector<int> mrk;

/** read file */
void read() {
	cin >> N;
	p.resize(N);
	mrk.resize(N);
	for(int j = 0; j < N; j++){
		mrk[j] = 0;
	}
	for(int i = 0; i < N; i++){
		cin >> p[i];
		sum += p[i];
	}
	std::sort(p.begin(), p.end());
}


/** search */
ll s = 0;

int K = 0;

void dfs(int n) {
	for(int i = K; i < N; i++){
		if(mrk[i] == 1){
			continue;
		}
		mrk[i] = 1;
		s += p[i];

		if(s >= sum / 2.0){
			m = min(s - sum / 2.0 , m);
			s -= p[i]; mrk[i] = 0;
			return;
		}

		K = i + 1;
		dfs(n + 1);

		s -= p[i];
		mrk[i] = 0;
	}
}


/*************/
int main() {
	read();
	dfs(0);
	
	cout << (ll) (m*2 + 0.001) << endl;
}
