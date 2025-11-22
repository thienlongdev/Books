#include <bits/stdc++.h>
#define faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;
int main()
{
    faster();
    int n;
    long long b;
    cin >> n >> b;
    vector<long long> a(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> c[i];
    long long maxValue = 0;
    vector<int> best(n, 0);
    for (int mask = 0; mask < (1 << n); mask++)
    {
        long long totalWeight = 0;
        long long totalValue = 0;
        vector<int> current(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                totalWeight += a[i];
                totalValue += c[i];
                current[i] = 1;
            }
        }
        if (totalWeight <= b && totalValue > maxValue)
        {
            maxValue = totalValue;
            best = current;
        }
    }
    cout << maxValue << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << best[i] << ' ';
    }
    cout << '\n';
    return 0;
}
