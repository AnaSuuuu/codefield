#include<bits/stdc++.h>
using namespace std;
const int N = 31;
const int M = 15000005;
struct Node {
	double sum;
	int sta, cnt;
};
int maxn, tot1, tot2;
double v[N];
map<int, int> vis;
map<int, Node> a, b;
void dfs(int dep, int sta, int cnt, double sum, int fla) {
	if(dep == maxn + 1) {
		if(fla) {
			a[++tot1].sta = sta;
			a[tot1].sum = sum;
			a[tot1].cnt = cnt;
		}
		else {
			b[++tot2].sta = sta;
			b[tot2].sum = sum;
			b[tot2].cnt = cnt;
		}
		return ;
	}
	dfs(dep + 1, sta, cnt, sum, fla);
	dfs(dep + 1, sta + (1 << (dep - 1)), cnt, sum + v[dep], fla);
	dfs(dep + 1, sta + (1 << (dep - 1)), cnt + 1, sum + v[dep] / 2, fla);
}
bool cmp1(Node x, Node y) {
	return x.sum < y.sum;
}
bool cmp2(Node x, Node y) {
	return x.sum > y.sum;
}
int main(){
	freopen("9234.in", "r", stdin);
	freopen("9234.out", "w", stdout);
	int n;
	double m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> v[i];
	maxn = n / 2;
	dfs(1, 0, 0, 0, 0);
	maxn = n;
	dfs(n / 2 + 1, 0, 0, 0, 1);
	int l = 1, r = 1, ans = 0x3f3f3f3f;
	sort(a + 1, a + 1 + tot1, cmp1);
	sort(b + 1, b + 1 + tot2, cmp2);
	//cout << tot1 << ' ' << tot2 << endl;
	//for(int i = 1; i <= tot1; i++) cout << a[i].sum << ' ';
	//cout << endl;
	// for(int i = 1; i <= tot2; i++) cout << b[i].sum << ' ';
	//cout << endl;
	while(l <= tot1 && r <= tot2) {
		while(a[l].sum + b[r].sum > m && r <= tot2) r++;
		int rev = r;
		while(a[l].sum + b[r].sum == m && r <= tot2) {
			if(!vis[a[l].sta | b[r].sta]) {
				vis[a[l].sta | b[r].sta] = 1;
				ans = min(ans, a[l].cnt + b[r].cnt);
			}
			r++;
		}
		//cout << l << ' ' << r << endl;
		if(a[l].sum == a[l + 1].sum) r = rev;
		l++;
	}
	cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
	return 0;
}

