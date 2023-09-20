#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int L[N], R[N], a[N];
int len[N], s[N];
int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int tot = 1;
	L[1] = 1;
	for(int i = 1; i <= n; i++) {
		if(a[i + 1] <= a[i] && a[i] > a[i - 1]) R[tot] = i, len[tot] = R[tot] - L[tot] + 1;
		else if(a[i - 1] >= a[i] && a[i] < a[i + 1]) L[++tot] = i;
	}
	if(R[tot] != n) L[++tot] = R[tot] = n, len[tot] = 1;
	//R[tot] = n, len[tot] = R[tot] - L[tot] + 1;
	//cout << tot << endl;
	for(int i = 1; i <= tot; i++) s[i] = s[i - 1] + len[i];
	//for(int i = 1; i <= tot; i++) cout << L[i] << ' ' << R[i] << endl;
	for(int i = 1; i <= q; i++){
		int l, r, ans = 0;
		cin >> l >> r;
		int nl = upper_bound(L + 1, L + 1 + tot, l) - L - 1;
		int nr = lower_bound(R + 1, R + 1 + tot, r) - R;
		//cout << nl << ' ' << nr << endl; 
		if(nl == nr){
			ans += r - l + 1;
			cout << ans << endl;
			continue;
		}
		if(R[nl] >= l) ans += R[nl] - l + 1;
		else ans++;
		if(L[nr] <= r) ans += r - L[nr] + 1;
		else ans++;
		if(nr - 1 >= nl + 1) ans += s[nr - 1] - s[nl];
		cout << min(ans, r - l + 1) << endl;
		//for(int i = nl + 1; i < nr; )
	}
	return 0;
}

