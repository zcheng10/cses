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


string str;
int cnt[26];
int N;

const int A = 26;
set<string> per;

/** read file */
void read() {
	cin >> str;
	N = str.length();
	for(int i = 0; i < A; i++){
		cnt[i] = 0;
	}
}

int fact(int n){
	if(n == 0){
		return 1;
	}
	if(n == 1){
		return 1;
	}
	return n*fact(n-1);
}



void alph(string& st){
	std::sort(st.begin(), st.end());
}

/** search */
void search() {
	for(int i = 0; i < N; i++){
		int l = str[i] - 'a';
		cnt[l]++;
	}
}

string s;

void dfs(int m){
	if(m == N){
		per.insert(s);
		return;
	}
	for(int i = 0; i < A; i++){
		if(cnt[i] == 0){
			continue;
		}
		s[m] = 'a' + i;
		cnt[i]--;
		dfs(m+1);
		cnt[i]++;
	}
}

/*************/
int main() {
	read();
	search();
	s.resize(N);
	dfs(0);
	int k = fact(N);
	for(int i = 0; i < A; i++){
		k /= fact(cnt[i]);
	}
	k = per.size();
	cout << k << endl;
	for(auto it : per){
		cout << it << endl;
	}
}
