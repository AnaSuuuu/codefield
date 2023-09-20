#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 20;
struct Node {
	ull sta, sum;
}a[(1 << N) + 5], b[(1 << N) + 5];
ull maxn, tot1, tot2;
ull v[N << 1];
map<ull, int> vis;
void dfs(ull dep, ull sta, ull sum, ull fla) {
	if(dep == maxn + 1) {
		if(fla) {
			a[++tot1].sta = sta;
			a[tot1].sum = sum;
		}
		else {
			b[++tot2].sta = sta;
			b[tot2].sum = sum;
		}
		return ;
	}
	dfs(dep + 1, sta, sum, fla);
	dfs(dep + 1, sta + (1 << (dep - 1)), sum + v[dep], fla);
}
bool cmp1(Node x, Node y) {
	return x.sum < y.sum;
}
bool cmp2(Node x, Node y) {
	return x.sum > y.sum;
}
int main(){
	freopen("4799.in", "r", stdin);
	freopen("4799.out", "w", stdout);
	ull n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> v[i];
	maxn = n / 2;
	dfs(1, 0, 0, 0);
	maxn = n;
	dfs(n / 2 + 1, 0, 0, 1);
	ull l = 1, r = 1, ans = 0;
	sort(a + 1, a + 1 + tot1, cmp1);
	sort(b + 1, b + 1 + tot2, cmp2);
	/*cout << tot1 << ' ' << tot2 << endl;
	for(int i = 1; i <= tot1; i++) cout << a[i].sum << ' ';
	cout << endl;
	for(int i = 1; i <= tot2; i++) cout << b[i].sum << ' ';
	cout << endl;*/
	while(l <= tot1 && r <= tot2) {
		while(a[l].sum + b[r].sum > m && r <= tot2) r++;
		if(r <= tot2) ans += tot2 - r + 1;
		l++;
	}
	cout << ans << endl;
	return 0;
}

