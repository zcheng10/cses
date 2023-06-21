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

int N;

/** read file */
void read() {
	cin >> N;
}

/** search */
void search() {
    int a = 1, b = 0;
    while (N > 0) {
        for (int i = 2; i <= N; i += 2) {
            cout << a * i + b << " ";
        }
        if (N % 2 == 1){
            cout << a + b << " ";
            b += a;
        }
        else{
            b -= a;
        }
        a *= 2;
        N /= 2;
    }
}

/*************/
int main() {
	read();
	search();

	cout << endl;
}
