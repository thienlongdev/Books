#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define s ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
struct Item{
    long long w, v;
    double ratio;
    int id;
};
int n;
long long B;
vector<Item> a;
long long fopt = 0;
vector<Item> xopt;
vector<Item> x;
long long currV = 0, currW = 0;
double bound(int k, long long currW, long long currV){
    double res = currV;
    long long remaining = B - currW;
    for (int i = k; i < n && remaining > 0; i++){
        if (a[i].w <= remaining){
            remaining -= a[i].w;
            res += a[i].v;
        }
        else{
            res += a[i].ratio * remaining;
            break;
        }
    }
    return res;
}
void Try(int k){
    if (k == n){
        if (currV > fopt){
            fopt = currV;
            xopt = x;
        }
        return;
    }
    if (currW + a[k].w <= B){
        currW += a[k].w;
        currV += a[k].v;
        x.push_back(a[k]);
        Try(k + 1);
        currW -= a[k].w;
        currV -= a[k].v;
        x.pop_back();
    }
    if (bound(k + 1, currW, currV) > fopt){
        Try(k + 1);
    }
}
int main(){
	s
    cin >> n >> B;
    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].w >> a[i].v;
        a[i].ratio = (double)a[i].v / a[i].w;
        a[i].id = i + 1;
    }
    sort(a.begin(), a.end(), [](Item A, Item B)
         { return A.ratio > B.ratio; });
    Try(0);
    cout << fopt << "\n";
    cout << xopt.size() << "\n";
    for (auto &it : xopt)
        cout << it.w << " " << it.v << "\n";
    return 0;
}
