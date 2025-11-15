#include<bits/stdc++.h>
using namespace std;

int c[50][50], n , fopt = 999999999;
vector<int> xopt;

// sinh hoan vi
int demHoanVi = 0;
int a[100] = {0};
bool chuaXet[100]; 
vector<int> hoanVi[500];


void result() {
	hoanVi[demHoanVi].push_back(1);
	for (int i = 1; i <= n; i++) {
		hoanVi[demHoanVi].push_back(a[i] + 1);
	}
	hoanVi[demHoanVi].push_back(1);
	demHoanVi++;
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


// duyet bai toan
void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
}

void duyet() {
	cout << std::left << "\n";
	cout << setw(20) << "X" << "|";
	cout << setw(20) << "f" << "|";
	cout << setw(20) << "fopt" << "\n";
	cout << string(60, '-') << "\n";
	cout << std::left;
	for (int i = 0; i < demHoanVi; i++) {
		vector<int> hv = hoanVi[i];
		string hvStr = "";
		for (auto i : hv) hvStr += to_string(i) + " ";
		cout << setw(20) << hvStr << "|";
		int f = 0;
		for (int i = 1; i < hv.size(); i++) {
			f += c[hv[i-1]][hv[i]];	
		}
		cout << setw(20) << f << "|";
		if (f < fopt) {
			fopt = f;
			xopt = hv;
			cout << setw(20) << fopt << "\n";
		} else {
			cout << setw(20) << "-" << "\n";
		}
	}
}


int main() {
	memset(chuaXet, true, sizeof(chuaXet));
	cin >> n;
	init();
	n--;
	Try(1);
	n++;
	duyet();
	cout << "\nKet qua: Fopt = ";
	cout << fopt << " Xopt = ";
	for (auto i : xopt) cout << i << " ";
}
