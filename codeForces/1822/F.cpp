#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
vector<vector <ll> > e;
vector<vector <ll> > D;
ll up[N];
struct Node{
	ll num = 0, id;
};
vector<pair<Node, Node> > kdl;//(N);
ll fa[N], dep[N];

void dfs(ll u, ll f, ll d){
	fa[u] = f;
	dep[u] = d;
  D[d].push_back(u);
	for(ll v: e[u]){
		if(v == f) continue;
		dfs(v, u, d + 1);
	}
	return ;
}
int main(){
	freopen("F.in", "r", stdin);
	freopen("F.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		ll n, k, c;
		scanf("%lld%lld%lld", &n, &k, &c);
    //cout << n << ' ' << k << ' ' << c << endl;
		e.clear();
		e.resize(n + 2);
    
    //cout << n << ' ' << k << ' ' << c << endl;
		D.clear();
		D.resize(n + 2);
    kdl.clear();
    kdl.resize(n + 2);
    //cout << n << ' ' << k << ' ' << c << endl;
    //puts("AAA");
    for(int i = 1; i <= n; i++) up[i] = 0;
    //cout << n << ' ' << k << ' ' << c << endl;
    for(int i = 1; i < n; i++){
			ll u, v;
			scanf("%lld%lld", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1, 0, 1);
		for(ll i = n; i >= 1; i--){
			for(ll u: D[i]){
				for(ll v: e[u]){
					if(v == fa[u]) continue;
					if(kdl[v].first.num + 1 > kdl[u].first.num){
						kdl[u].first.num = kdl[v].first.num + 1;
						kdl[u].first.id = v;/**/
					}
				}
				for(ll v: e[u]){
					if(v == fa[u] || v == kdl[u].first.id) continue;
					if(kdl[v].first.num + 1 > kdl[u].second.num){
						kdl[u].second.num = kdl[v].first.num + 1;
						kdl[u].second.id = v;
					}/**/
				}
			}
		}
    //puts("AAA");
    
    //cout << n << ' ' << k << ' ' << c << endl;
    up[1] = 0;
		for(int i = 2; i <= n; i++){
			for(int u: D[i]){
				int v = fa[u];
        //cout << u << ' ' << v << endl;
				up[u] = up[v] + 1;
				if(kdl[v].first.id != u) up[u] = max(up[u], kdl[v].first.num + 1);
				else up[u] = max(up[u], kdl[v].second.num + 1);
			}
		}
    
    //cout << n << ' ' << k << ' ' << c << endl;
    //for(int i = 1; i <= n; i++) cout << dep[i] << ' ';
    //cout << endl;
    //for(int i = 1; i <= n; i++) cout << up[i] << ' ';
    //cout << endl;
		ll ans = 0;
		for(int i = 1; i <= n; i++)
			ans = max(ans, k * max(up[i], kdl[i].first.num) - (dep[i] - 1) * c);
		printf("%lld\n", ans);/**/
    
    //cout << n << ' ' << k << ' ' << c << endl;
	}
	return 0;
}

