#include <bits/stdc++.h>
using namespace std;
#define s ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
int n;
long long c[20][20];
int a[20];
bool used[20];
long long fopt = LLONG_MAX;
vector<int> bestPath;
long long calcCost(const vector<int> &path)
{
    long long cost = 0;
    for (int i = 0; i + 1 < path.size(); i++)
        cost += c[path[i]][path[i + 1]];
    return cost;
}
void Try(int k)
{
    for (int v = 2; v <= n; v++)
    {
        if (!used[v])
        {
            used[v] = true;
            a[k] = v;

            if (k == n)
            {
                vector<int> path;
                path.push_back(1);
                for (int i = 2; i <= n; i++)
                    path.push_back(a[i]);
                path.push_back(1);
                long long total = calcCost(path);
                if (total < fopt)
                {
                    fopt = total;
                    bestPath = path;
                }
            }
            else
            {
                Try(k + 1);
            }

            used[v] = false;
        }
    }
}

int main()
{
	s
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    memset(used, false, sizeof(used));
    a[1] = 1;
    used[1] = true;
    Try(2);
    cout << fopt << "\n";
    for (int i = 0; i < n; i++)
        cout << bestPath[i] << " ";
    return 0;
}
