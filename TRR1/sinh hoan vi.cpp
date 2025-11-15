#include <bits/stdc++.h>
using namespace std;
int a[100] = {0}, n;

void result() {
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

void init() {
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
}

void Try() {
	result();
	int i = n-1;
	while (i > 0) {
		if (a[i] < a[i+1]) break;
		i--;
	}
	if (i == 0) return;
	int j, k = n;
	while (a[k] < a[i]) k--;
	swap(a[i], a[k]);
	j = i + 1; k = n;
	while (j < k) {
		int tmp = a[j];
		a[j] = a[k];
		a[k] = tmp;
		j++; k--;
	}
	Try();
	
}

int main() {
	cin >> n;
	init();
	Try();
	return 0;
}
