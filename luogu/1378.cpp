#include<bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535;
int x[10], y[10];
int n, x0, x1, y00, y11, ans = 0x3f3f3f3f;
bool vis[10];
double dis[10][10], r[10];
void dfs(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(vis[i]) {
			cnt++;
			continue;
		}
		r[i] = min(min(x[i] - x1, x0 - x[i]), min(y[i] - y00, y11 - y[i]));
		for(int j = 1; j <= n; j++){
			if(!vis[j]) continue;
			r[i] = min(r[i], sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - r[j]);
		}
		r[i] = max(0.0, r[i]);
		vis[i] = 1;
		dfs();
		vis[i] = 0;
	}
	if(cnt == n){
		double S = 0;
		for(int i = 1; i <= n; i++) S += pi * r[i] * r[i];//, cout << r[i] << endl;
		ans = min(ans, (int) ((x0 - x1) * (y11 - y00) - S + 0.5));
	}
		
}
int main(){
	freopen("1378.in", "r", stdin);
	freopen("1378.out", "w", stdout);
	cin >> n;
	cin >> x0 >> y00 >> x1 >> y11;
	if(y11 < y00) y11 ^= y00 ^= y11 ^=y00;
	if(x0 < x1) x0 ^= x1 ^= x0 ^= x1; 
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	dfs();
	cout << ans << endl;
	return 0;
}

