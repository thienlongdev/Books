#include <bits/stdc++.h>
using namespace std;
int a[100] = {0}, n, k;

void result() {
	for (int i = 1; i <= k; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

void init() {
	for (int i = 1; i <= k; i++) {
		a[i] = i;
	}
}

void Try() {
	result();
	int i = k;
	while (i > 0) {
		if (a[i] < n - k + i) break;
		i--;
	}
	if (i == 0) return;
	a[i]++;
	for (int j = i + 1; j <= k; j++) a[j] = a[j-1] + 1;
	Try();
}

int main() {
	cin >> n >> k;
	init();
	Try();
	return 0;
}
