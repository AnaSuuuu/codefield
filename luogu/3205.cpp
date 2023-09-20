#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const int mod = 19650827;
int h[N], f[N][N][2];
int main(){
	freopen("3205.in", "r", stdin);
	freopen("3205.out", "w", stdout);
	int n;
	cin >> n;
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++) cin >> h[i], f[i][i][0] = 1;
	for(int len = 1; len < n; len++){
		for(int i = 1; i + len <= n; i++){
			int j = i + len;
			if(h[i + 1] > h[i]) f[i][j][0] = (f[i][j][0] + f[i + 1][j][0]) % mod;
			if(h[j] > h[i]) f[i][j][0] = (f[i][j][0] + f[i + 1][j][1]) % mod;
			if(h[j - 1] < h[j]) f[i][j][1] = (f[i][j][1] + f[i][j - 1][1]) % mod;
			if(h[i] < h[j]) f[i][j][1] = (f[i][j][1] + f[i][j - 1][0]) % mod;
		} 
	}
	cout << (f[1][n][0] + f[1][n][1]) % mod << endl;
	return 0;
}

