#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
map<ll, ll> cnt;
ll a[N];
void in(ll &x){
	ll f = 1;
	x = 0;
	char c = getchar();
	while(c > '9' || c < '0'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c - '0');
		c = getchar();
	}
	x *= f;
}
int main(){
	freopen("G.in", "r", stdin);
	freopen("G.out", "w", stdout);
	ll t;
	in(t);
	while(t--){
		ll n, maxn = 0;
		ll ans = 0;
		in(n);
		//memset(cnt, 0, sizeof(cnt));
		cnt.clear();
		for(ll i = 1; i <= n; i++) {
			in(a[i]);
			maxn = max(maxn, a[i]);
			cnt[a[i]]++;
		}
		sort(a + 1, a + 1 + n);
		//cout << maxn << endl;
		for(ll i = 1; i <= n; i++){
			ll num = cnt[a[i]]; 
			if(a[i] == a[i - 1]) continue;
			if(a[i] != a[i - 1] && cnt[a[i]] >= 3) ans += 1ll * num * (cnt[a[i]] - 1) * (cnt[a[i]] - 2);
			if(a[i] > 1e6){ 
				for(int j = 2; j * a[i] <= maxn && j * 2 <= a[i]; j++)	{
					if(a[i] % j == 0 && cnt[a[i] * j] && cnt[a[i] / j]) ans += num * cnt[a[i] * j] * cnt[a[i] / j];
				}
				if(cnt[1] && cnt[a[i]] && cnt[a[i] * a[i]]) ans += num * cnt[1] * cnt[a[i] * a[i]];
			}
			else {
				for(int j = 1; j * j <= a[i] && a[i] * j <= maxn; j++){
					if(a[i] % j == 0){
						if(cnt[a[i] * j] && cnt[a[i] / j] && j != 1) ans += num * cnt[a[i] * j] * cnt[a[i] / j];
						if(a[i] * a[i] / j <= maxn && j != a[i] / j && cnt[a[i] * (a[i] / j)] && cnt[a[i] / (a[i] / j)]) ans += num * cnt[a[i] * (a[i] / j)] * cnt[a[i] / (a[i] / j)];
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

