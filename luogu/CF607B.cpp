#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int c[N], f[N][N];
int main(){
	freopen("CF607B.in", "r", stdin);
	freopen("CF607B.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++) f[i][i] = 1, f[i][i - 1] = 1;
	for(int len = 1; len <= n; len++){
		for(int i = 1; i + len <= n; i++){
			int j = i + len;
			for(int k = i; k < j; k++)
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
			if(c[i] == c[j]) f[i][j] = min(f[i][j], f[i + 1][j - 1]);
		} 
	}
	cout << f[1][n] << endl;
	return 0;
}

