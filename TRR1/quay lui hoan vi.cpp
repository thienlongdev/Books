#include <bits/stdc++.h>
using namespace std;

int a[100] = {0}, n;
bool chuaXet[100];
void result() {
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

void Try(int m) {
	for (int i = 1; i <= n; i++) {
		if (chuaXet[i]) {
			chuaXet[i] = false;
			a[m] = i;
			if (m == n) result();
			else Try(m + 1);
			chuaXet[i] = true;
		}
	}
}


int main() {
	memset(chuaXet, true, sizeof(chuaXet));
	cin >> n;
	Try(1);
}
