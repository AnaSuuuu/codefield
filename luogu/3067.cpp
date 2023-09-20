#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 25;
ll a[N], sum, ans, n;
bool cmp(int x, int y) {
	return x > y;
}
void dfs(int pos, int tot) {
	if(pos == n + 1) return ;
	if(tot == sum) {
		ans++;
		return ;
	}
	if(tot + a[pos] <= sum) dfs(pos + 1, tot + a[pos]);
	dfs(pos + 1, tot);
}
int main(){ 
	freopen("3067.in", "r", stdin);
	freopen("3067.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	sort(a + 1, a + 1 + n, cmp);
	sum >>= 1;
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}

