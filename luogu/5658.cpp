#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int maxn, tot1, tot2, c[N];
struct Node {
	int sum, sta;
}a[1 << N], b[1 << N];
void dfs(int dep, int sum, int sta, int fla) {
	if(dep == maxn + 1) {
		if(fla) {
			a[++tot1].sta = sta;
			a[tot1].sum = sum;
			return ;
		}
		else {
			b[++tot2].sta = sta;
			b[tot2].sum = sum;
			return ;
		}
	}
	dfs(dep + 1, sum, sta, fla);
	dfs(dep + 1, sum + c[dep], sta | (1 << (dep - 1)), fla);
	dfs(dep + 1, sum - c[dep], sta | (1 << (dep - 1)), fla);
}
bool cmp1 (Node x, Node y) {
	return x.sum < y.sum;
}
bool cmp2 (Node x, Node y) {
	return x.sum > y.sum;
}
bool vis[1 << N];
int main(){
	freopen("5658.in", "r", stdin);
	freopen("5658.out", "w", stdout);
	int n;
	scanf("%d\n", &n);
	for(int i = 1; i <= n; i++) cin >> c[i]; 
	maxn = n / 2;
	dfs(1, 0, 0, 1);
	maxn = n;
	dfs(n / 2 + 1, 0, 0, 0);
	int l = 1, r = 1, ans = 0;
	sort(a + 1, a + 1 + tot1, cmp1);
	sort(b + 1, b + 1 + tot2, cmp2);
	//cout << tot1 << ' ' << tot2 << endl;
	while(l <= tot1 && r <= tot2) {
		while(b[r].sum + a[l].sum > 0 && r <= tot2) r++;
		int rev = r;
		while(b[r].sum + a[l].sum == 0 && r <= tot2) {
			if(!vis[a[l].sta | b[r].sta]) {
				ans++;
				vis[a[l].sta | b[r].sta] = 1;
			}
			r++;
		}
		if(a[l].sum == a[l + 1].sum) r=rev;
		l++;
	}
	cout << ans - 1 << endl;
	return 0;
}

