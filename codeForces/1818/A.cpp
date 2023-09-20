#include<bits/stdc++.h>
using namespace std;
const int N = 105;
char s[N][N];
int vis[N];
int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		scanf("%d%d\n", &n, &k);
		for(int i = 1; i <= n; i++) vis[i] = 1;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= k; j++){
				scanf("%c", &s[i][j]);
			}
			scanf("\n");
		}
		int ans = 0;
		for(int i = 1; i <= k; i++){
			for(int j = 2; j <= n; j++) if(s[j][i] != s[1][i]) vis[j] = 0; 
		}
		//for(int i = 1; i <= n; i++)cout << vis[i] << ' ';
		//cout << endl;
		for(int i = 1; i <= n; i++) ans += vis[i];
		cout << ans << endl;
	}
	return 0;
}

