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

int q;

vector<ll> k;
vector<ll> S;
vector<ll> m10; // 10^i


/** read file */
void read() {
	cin >> q;
	k.resize(q);
	for(int i = 0; i < q; i++){
		cin >> k[i];
	}
	m10.resize(19);
	m10[0] = 1;
	for(int j = 1; j < 19; j++){
		m10[j] = m10[j-1]*10;
	}
	S.resize(1);
	S[0] = 0;
	int a = 1;
	while(a <= 19){
		S.push_back(S[a - 1] + a*9* m10[a - 1]);
		a++;
	}

}


/** search */
void search(ll a) {
	for(int i = 0; i < S.size(); i++){
		if(S[i] < a && S[i+1] >= a){
			ll b = a - S[i];
			ll num = m10[i] - 1 + b/(i+1);
			if(b % (i +1) != 0){
				num++;
			}
			ll mod = (b) % (i+1);
			if(mod == 0){
				mod = i + 1;
			}
			int ans = num/m10[i + 1 - mod] % 10;
			cout << ans << endl;
			return;
		}
	}
}

/*************/ 
int main() {
	read();
	for(int i = 0; i < q; i++){
		search(k[i]);
	}

	//cout << endl;
}
