#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N];
int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		int n, l = 0x3f3f3f3f, r = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for(int i = 1; i <= n; i++) {
			if(a[i] != b[i]) l = min(l, i), r = max(r, i);
		}
		for(int i = r + 1; i <= n; i++) {
			if(b[i] >= b[i - 1]) r++;
			else break;
		}
		for(int i = l - 1; i >= 1; i--){
			if(b[i] <= b[i + 1]) l--;
			else break;
		}
		printf("%d %d\n", l, r);
	}
	return 0;
}

