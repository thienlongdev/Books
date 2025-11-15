#include<bits/stdc++.h>
using namespace std;

int n, b, f, fopt = -9999999;
string xopt;
vector<int> xauNp[500];
int cnt = 0;
int w[100], c[100];
// quay lui sinh nhi phan
int a[100] = {0};

void init() {
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
}

void result() {
	for (int i = 1; i <= n; i++) {
		xauNp[cnt].push_back(a[i]);
	}
	cnt++;
}

void Try(int m) {
	for (int i = 0; i <= 1; i++) {
		a[m] = i;
		if (m == n) result();
		else Try(m+1);
	}
}

void duyet() {
	int sumW = 0, sumC = 0;
	for (int i = 0; i < cnt; i++) {
		vector<int> xau = xauNp[i];
		sumW = 0, sumC = 0;
		for (int i = 0; i < xau.size(); i++) {
			sumW += w[i] * xau[i];
			sumC += c[i] * xau[i];
		}
		string xauHienTai = "";
		for (auto i : xau) xauHienTai += to_string(i) + " ";
		cout << setw(15) << xauHienTai << "|";
		if (sumW <= b) {
			cout << setw(15) << sumW << "|";
			cout << setw(15) << "Yes" << "|";
			cout << setw(15) << sumC << "|";
			if (sumC > fopt) {
				fopt = sumC;
				xopt = xauHienTai;
				cout << setw(15) << fopt << "|";
			} else {
				cout << setw(15) << '-' << "|";
			}
			
		} else {
			cout << setw(15) << to_string(sumW)  << "|";
			cout << setw(15) << "No" << "|";
			cout << setw(15) << '-'  << "|";
			cout << setw(15) << '-' << "|";
		}
		cout << "\n";
	}
	
}

int main() {
	cout << "Nhap so bien x: ";
	cin >> n;
	cout << "Nhap gioi han can nang: ";
	cin >> b;
	init();
	Try(1);
	cout << std::left << "\n";
	cout << setw(15) << "X" << "|";
	cout << setw(15) << "g(X)" << "|";
	cout << setw(15) << "g(X) < b?" << "|";
	cout << setw(15) << "f(X)" << "|";
	cout << setw(15) << "fopt" << "\n";
	duyet();
	cout << "fopt: " << fopt << " xopt: " << xopt;
	
}
