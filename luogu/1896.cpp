#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[15][1505][105];
ll sta[1505], tot, num[1505];
int n, k;
void out(int x){
	if(x == 0){
		puts("0");
		return ;
	}
	while(x) {
		cout << (x % 2);
		x >>= 1;
	}
	cout << endl;
}
void dfs(int ss, int pos, int dig) {
	num[ss] = dig;
	if(pos == n) return ;
	int ss1 = ss + (1 << pos);
	//out(ss);
	if((ss1 & (ss1 << 1)) == 0) sta[++tot] = ss1;
	dfs(ss, pos + 1, dig);
	dfs(ss1, pos + 1, dig + 1);
}

int main(){
	freopen("1896.in", "r", stdin);
	freopen("1896.out", "w", stdout);
	cin >> n >> k;
	dfs(0, 0, 0);
	sta[++tot] = 0;
	//cout << tot << endl;
	//for(int i = 1; i <= tot; i++) out(sta[i]);
	for(int i = 1; i <= tot; i++) f[1][sta[i]][num[sta[i]]] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= tot; j++){
			for(int x = 1; x <= tot; x++){
				if((sta[j] & sta[x]) || ((sta[j] << 1) & sta[x]) || ((sta[j] >> 1) & sta[x])) continue;
				//out(sta[j]); out(sta[x]); puts("AAA");
				for(int h = k; h >= num[sta[j]] + num[sta[x]]; h--) f[i][sta[j]][h] += f[i - 1][sta[x]][h - num[sta[j]]];  
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= tot; i++) ans += f[n][sta[i]][k];
	//for(int i = 1; i <= tot; i++) cout << f[n][sta[i]][k] << ' ';
	//cout << endl;
	//cout << f[1][0][0] << ' ' << f[2][0][0] << ' ' << f[3][0][0] << endl;
	cout << ans << endl;
	return 0;
}

