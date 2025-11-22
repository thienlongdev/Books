#include <bits/stdc++.h>
using namespace std;
int n;
long long c[20][20];
int x[20];
bool used[20];
long long f = 0;
long long fopt = LLONG_MAX;
int best[20];
long long cmin = LLONG_MAX;
void Try(int k)
{
    for (int v = 2; v <= n; v++)
    {
        if (!used[v])
        {
            x[k] = v;
            used[v] = true;
            f += c[x[k - 1]][v];
            long long g = f + (n - k + 1) * cmin;
            if (g < fopt)
            {
                if (k == n)
                {
                    long long total = f + c[v][1];
                    if (total < fopt)
                    {
                        fopt = total;
                        for (int i = 1; i <= n; i++)
                            best[i] = x[i];
                    }
                }
                else
                {
                    Try(k + 1);
                }
            }
            used[v] = false;
            f -= c[x[k - 1]][v];
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (i != j)
                cmin = min(cmin, c[i][j]);
        }
    x[1] = 1;
    used[1] = true;
    Try(2);
    cout << fopt << "\n";
    for (int i = 1; i <= n; i++)
        cout << best[i] << " ";

    return 0;
}
