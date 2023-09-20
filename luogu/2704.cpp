#include<bits/stdc++.h>
using namespace std;
const int N = 105; 
string s[N];
int M[N][N], f[1 << 10][1 << 10][3];
int sum[1 << 10], a[N];
int get_digital(int x){
	int num = 0;
	while(x){
		num += (x % 2);
		x >>= 1;
	}
	return num;
}
int main(){
	freopen("2704.in", "r", stdin);
	freopen("2704.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i < (1 << m); i++) sum[i] = get_digital(i);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++){
			char c;
			cin >>c;
			M[i][j] = (c == 'H' ? 1: 0); 
			a[i] = (a[i] << 1) + M[i][j];
		}
	}
	for(int i = 0; i < (1 << m); i++) f[0][i][1] = sum[i];
	for(int i = 0; i < (1 << m); i++) {
		if((i & a[1]) || (i & (i << 1)) || (i & (i << 2))) continue;
		for(int j = 0; j < (1 << m); j++) {
			if((j & a[2]) || (j & (j << 1)) || (j & (j << 2))) continue;
			if(i & j) continue;
			f[i][j][2] = sum[i] + sum[j];
		}
	}
	for(int i = 3; i <= n; i++){
		for(int j = 0; j < (1 << m); j++){
			if((j & a[i - 2]) || (j & (j << 1)) || (j & (j << 2))) continue;
			for(int k = 0; k < (1 << m); k++){
				if((k & a[i - 1]) || (k & (k << 1)) || (k & (k << 2))) continue;
				if(k & j) continue;
				for(int l = 0; l < (1 << m); l++){
					if((l & a[i]) || (l & (l << 1)) || (l & (l << 2))) continue;
					if((l & k) || (l & j)) continue;
					f[k][l][i % 3] = max(f[k][l][i % 3], f[j][k][(i + 2) % 3] + sum[l]);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < (1 << m); i++)
		for(int j = 0; j < (1 << m); j++)
			ans = max(ans, f[i][j][n % 3]);
	cout << ans << endl;
	return 0;
}

