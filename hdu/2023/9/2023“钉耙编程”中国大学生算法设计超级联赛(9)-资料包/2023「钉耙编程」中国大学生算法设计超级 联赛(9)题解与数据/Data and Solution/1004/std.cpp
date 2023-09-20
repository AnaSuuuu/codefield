#include <bits/stdc++.h>
#define fp(i, a, b) for(int i = (a), ed = (b); i <= ed; ++i)
#define fb(i, a, b) for(int i = (a), ed = (b); i >= ed; --i)
using namespace std;
inline int rd() {
	register int x(0), f(1); register char c(getchar());
	while (c < '0' || '9' < c) { if (c == '-')f = -1; c = getchar(); }
	while ('0' <= c && c <= '9')x = x*10 + c-'0', c = getchar();
	return x*f;
}
const int maxn = 55, maxm = 1<<15, mod = 998244353;
int n, m, f[maxn][maxm], g[maxn][maxm], sum[maxm], isum[maxm];
struct edge{int u, v, w, p;}e[maxn];
inline int fpow(int a, int b, int ans = 1){
	for(; b; b >>= 1, a = 1ll*a*a%mod)if(b&1)ans = 1ll*ans*a%mod;
	return ans;
}
inline void solve(){
	memset(f, 0, sizeof f), memset(g, 0, sizeof g);
	memset(sum, 0, sizeof sum), memset(isum, 0, sizeof isum);
	n = rd(), m = rd();
	fp(i, 1, m)e[i].u = rd(), e[i].v = rd(), e[i].w = rd(), e[i].p = rd();
	sort(e+1, e+1+m, [](edge &x, edge &y){return x.w < y.w;});
	fp(i, 1, n)f[0][1<<i-1] = 1;
	fp(i, 0, (1<<n)-1)sum[i] = isum[i] = 1;
	fp(i, 1, m){
		fp(s, 0, (1<<n)-1){
			f[i][s] = f[i-1][s], g[i][s] = g[i-1][s];
			if(!(s>>e[i].u-1&1) || !(s>>e[i].v-1&1))continue;
			int tmp = s^(1<<e[i].u-1)^(1<<e[i].v-1);
			for(int t = tmp;; t = t-1&tmp){
				int L = t^(1<<e[i].u-1), R = (tmp^t)^(1<<e[i].v-1);
				int exp = (1ll*f[i-1][L]*g[i-1][R] + 1ll*g[i-1][L]*f[i-1][R] + 1ll*e[i].w*f[i-1][L]%mod*f[i-1][R])%mod;
				int pos = 1ll*e[i].p*sum[s]%mod*isum[L]%mod*isum[R]%mod;
				f[i][s] = (f[i][s] + 1ll*pos*f[i-1][L]%mod*f[i-1][R])%mod;
				g[i][s] = (g[i][s] + 1ll*exp*pos)%mod;
				if(!t)break;
			}
			sum[s] = 1ll*sum[s]*(1-e[i].p+mod)%mod, isum[s] = fpow(sum[s], mod-2);
		}
	}
	printf("%d\n", g[m][(1<<n)-1]);
}
int main(){
	int T = rd();
	while(T--)solve();
	return 0;
}