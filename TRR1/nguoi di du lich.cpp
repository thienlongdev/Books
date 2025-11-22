#include <bits/stdc++.h>
using namespace std;

int c[50][50], n , fopt = 1e9;
vector<int> xopt;

int demHoanVi = 0;
int a[100] = {0};
bool chuaXet[100]; 
vector<vector<int>> hoanVi(500);

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

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
}

void duyet() {
    for (int k = 0; k < demHoanVi; k++) {
        auto &hv = hoanVi[k];

        int f = 0;
        for (int i = 1; i < hv.size(); i++) {
            f += c[hv[i-1]][hv[i]];
        }
        if (f < fopt) {
            fopt = f;
            xopt = hv;
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

    cout << fopt << "\n";

    for (int i = 0; i < xopt.size() - 1; i++) {
        cout << xopt[i] << " ";
    }
}
