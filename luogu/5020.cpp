#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 25005;
int a[N];
bool vis[M];
int main(){
	freopen("5020.in", "r", stdin);
	freopen("5020.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, tot = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		for(int i = 1; i <= a[n]; i++) vis[i] = 0;
		for(int i = 1; i <= n; i++) {
			if(vis[a[i]]) continue;
			vis[a[i]] = 1; tot++;
			for(int j = 1; j + a[i] <= a[n]; j++) if(vis[j]) vis[j + a[i]] = 1;
		}
		cout << tot << endl;
	}
	return 0;
}

