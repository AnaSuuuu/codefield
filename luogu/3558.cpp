#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int pre[N], suf[N];
int main(){
	freopen("3558.in", "r", stdin);
	freopen("3558.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	suf[n] = 1 - a[n], pre[1] = 1 + a[1];
	for(int i = n - 1; i >= 1; i--) 
		suf[i] = suf[i + 1] + 1 - a[i];
	for(int i = 2; i <= n; i++) 
		pre[i] = pre[i - 1] + a[i] + 1;
	if(a[1] == 0) {
		for(int i = 2; i <= n; i++) {
			if(a[i] == 0) continue;
			if(a[i] == -1) {
				puts("BRAK");
				return 0;
			}
			if(a[i] == 1) {
				printf("%d\n", suf[i]);
				return 0;
			}
		}
	}
	if(a[1] == 1) {
		printf("%d\n", suf[1]);
		return 0;
	}
	int ans = pre[n];
	for(int i = 1, j; i <= n; i = j) {
		if(a[i] == -1) {
			j = i + 1;
			continue;
		}
		if(a[i] == 1) ans = min(ans, pre[i - 1] + suf[i]);
		for(j = i + 1; a[j] == 0 && j <= n; j++);
		if(j == n + 1) ans = min(ans, pre[i - 1] + (a[i] == 1));
		if(a[j] == -1) continue;
		ans = min(ans, pre[i - 1] + suf[j] + (a[i] == 1));
	}
	cout << ans << endl;
	return 0;
}

