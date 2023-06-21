#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
// Common file
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #include "C:/usaco/util/snipet.cpp"



int N, k;
ordered_set num;


/** read file */
void read() {
	cin >> N >> k;
	for (int i = 0; i < N; i++) {
		num.insert(i + 1);
	}
}

/** search */
void search() {
	int p = k % N;
	while (N--) {
		auto it = num.find_by_order(p);
		cout << *it << " ";
		num.erase(it);
		if (N) {
			p = (p + k) % N;
		}
	}
}

/*************/
int main() {
	read();
	search();

	cout << endl;
}
