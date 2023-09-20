#include<bits/stdc++.h>
using namespace std;
const int N = 305;
int l[N], r[N];
int f[N][N];
int main(){
	freopen("1063.in", "r", stdin);
	freopen("1063.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &l[i]);
		r[i - 1] = l[i];
		l[i + n] = l[i];
		r[i + n - 1] = l[i];
	}
	r[n] = r[2 * n] = l[1];
	for(int len = 1; len < n; len++){
		for(int i = 1; i + len <= 2 * n; i++){
			int j = i + len;
			for(int k = i; k < j; k++){
				f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + l[i] * r[j] * l[k + 1]);
 			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, f[i][i + n - 1]);
	cout << ans << endl;
	return 0;
}

