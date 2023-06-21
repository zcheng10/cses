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
int cnt = 1;

struct Event{
	int a;
	int b;

	bool operator < (const Event& e) const{
		return b < e.b;
	}
};

vector<Event> ev;

/** read file */
void read() {
	cin >> N;
	ev.resize(N);
	for(int i = 0; i < N; i++){
		cin >> ev[i].a >> ev[i].b;
	}
	sort(ev.begin(), ev.end());
}

/** search */

void search() {
	if(ev.size() == 0){
		return;
	}
	if(ev.size() == 1){
		cnt++;
		return;
	}
	cnt++;
	for(int i = (int) ev.size()-1; i >= 0; i--){
		if(ev[i].a < ev[0].b){
			ev.erase(ev.begin()+i);
		}
	}
	search();
}

void search2(){
	int B = ev[0].b;
	for(int i = 0; i < ev.size(); i++){
		if(ev[i].a >= B){
			cnt++;
			B = ev[i].b;
		}
	}
}

/*************/
int main() {
	read();
	//search();
	search2();

	cout << cnt << endl;
}
