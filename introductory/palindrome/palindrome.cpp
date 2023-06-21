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
char aph[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int cnt[26];
vector<string> ans;
string pal;

string str;
vector<int> vec;

/** read file */
void read() {
	cin >> str;
	for(int i = 0; i < 26; i++){
		cnt[i] = 0;
	}
}

/** search */
void search() {
	bool m = false;
	int odd;
	int ct2 = 0;
	for(int i = 0; i < str.length(); i++){
		for(int j = 0; j < 26; j++){
			if(str[i] == aph[j]){
				cnt[j]++;
			}
		}
	}
	for(int k = 0; k < 26; k++){
		if(cnt[k] % 2 == 1){
			if(m == true){
				cout << "NO SOLUTION" << endl;
				pal = "";
				return;
			}
			m = true;
			odd = k;
		}
		if(cnt[k] != 0){
			ct2++;
		}
	}
	int ct3 = 0;
	if(m){
		ans.resize(ct2*2+1);
	} else{
		ans.resize(ct2*2);
	}
	for(int l = 0; l < 26; l++){
		if(cnt[l] != 0){
			if(cnt[l] % 2 == 1){
				for(int b = 0; b < cnt[l]; b++){
					ans[ct2] += aph[l];
				}
			} else{
				for(int a = 0; a < cnt[l]/2; a++){
					ans[ct3] += aph[l];
					ans[2*ct2 - ct3 - 1] += aph[l];
				}
			}
			ct3++;
		}
	}
	for(int q= 0; q < ans.size(); q++){
		pal += ans[q];
	}
}

/*************/
int main() {
	read();
	search();
	cout << pal << endl;
}
