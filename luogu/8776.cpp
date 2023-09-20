#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], pre[N], suf[N];
int main(){
	freopen("8776.in", "r", stdin);
	freopen("8776.out", "w", stdout);
	int n, k, ans = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) pre[i] = (a[i] >= a[i - 1] ? pre[i - 1] + 1 : 1), ans = max(ans, pre[i] + k);
	for(int i = n; i >= 1; i--) suf[i] = (a[i] <= a[i + 1] ? suf[i + 1] + 1 : 1), ans = max(ans, suf[i] + k);
	for(int i = 0; i + k <= n; i++) 
		if(a[i] <= a[i + k + 1]) ans = max(ans, pre[i] + suf[i + 1 + k] + k);
	//cout << pre[2] << ' ' << suf[4] << endl;
	/*for(int i = 1; i <= n; i++) cout << pre[i] << ' ';
	cout << endl;
	for(int i = 1; i <= n; i++) cout << suf[i] << ' ';
	cout << endl;*/
	cout << ans << endl;
	return 0;
}

