#include <bits/stdc++.h>
using namespace std;

int a[100] = {0}, n;

void result() {
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

void Try(int m) {
	for (int i = 0; i <= 1; i++) {
		a[m] = i;
		if (m == n) result();
		else Try(m+1);
	}
}


int main() {
	cin >> n;
	Try(1);
}
