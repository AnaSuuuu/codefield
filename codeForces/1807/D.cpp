#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], sum[N];
int main(){
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		int n, q;
		scanf("%d%d", &n, &q);
		memset(sum, 0, sizeof(sum));
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			a[i] %= 2;
			sum[i] = sum[i - 1] + a[i], sum[i] %= 2;
		}
		while(q--){
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			if((sum[n] - (sum[r] - sum[l - 1]) + (k % 2) * (r - l + 1) % 2 + 2) % 2) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}

