#include <bits/stdc++.h>
using namespace std;

bool sinh(vector<int> &a, int n, int k){
	int i = k;
	while(i > 0 && a[i] == n - k + i) --i;
	if(i == 0) return false;
	++a[i];
	for(int j = i + 1; j <= k; ++j)
		a[j] = a[j - 1] + 1;
	return true;
}

int main(){
	int n, k, t;
	cin >> n >> k >> t;
	vector<int> a(k + 1);
	for(int i = 1; i <= k; ++i) cin >> a[i];
	while(t--){
		if(sinh(a, n, k)){
			for(int i = 1; i <= k; ++i){
				cout << a[i];
				if(i < k) cout << " ";
			}
			cout << '\n';
		}
		else{
			cout << 0 << '\n';
		}
	}
}