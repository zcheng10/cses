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

int n, m;
vector<int> h;
vector<int> t;
vector<int> mark;
vector<int> prev;
vector<int> next;
int x;

/** read file */
void read() {
	cin >> n >> m;
	h.resize(n+1);
	t.resize(m);
	mark.resize(n);
	for(int i = 0; i < n; i++){
		cin >> h[i]; 
	}
	for (int k = 0; k < n; k++) {
		mark[k] = 0;
	}
	h[n] = 1e9+1;
	for(int j = 0; j < m; j++){
		cin >> t[j];
	}
	sort(h.begin(), h.end());
	//sort(t.begin(), t.end());
}


int binary(int l, int r, int x){
	while (r >= l) {
		//cout << r << " " << l << endl;
        int mid = (r + l) / 2;
        // If the element is present at the middle
        // itself
        if ((h[mid] <= x && h[mid+1] > x)) {
			/*while (mark[mid] == 1 && mid > 0) {
				mid--;
			}
			if (mark[mid] == 1) {
				return -1;
			}
			mark[mid] = 1;*/
			int a = h[mid];
			//cout << "x = " << x << endl;
			h.erase(h.begin() + mid);
			return a;
		}
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (h[mid] > x){
            //return binary(l, mid - 1, x);
			r = mid - 1;
			continue;
		}
		l = mid + 1;
        // Else the element can only be present
        // in right subarray
        //return binary(mid + 1, r, x);
    }
	return -1;
}
/** search */
void search() {
	for(int i = 0; i < m; i++){
		if(i >= n){
			cout << "-1" << endl;
			continue;
		}
		int m;
			m = binary(0, (int) h.size()-1, t[i]);
		cout << m << endl;
	}
}

/*************/
int main() {
	read();
	search();

	//cout << endl;
}
