#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int a[N], ok;
ll sum[N];
int cal(int x){
	int kdl = 1;
	while(kdl <= x) kdl <<= 1;
	return kdl >> 1;
}
void Q(int l, int r){
	if(ok) return ;
	if(l == r){
		printf("? 1 %d\n", l);
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if(x != a[l]) {
			ok = 1;
			printf("! %d\n", l);
			fflush(stdout);
		}
		return ;
	}
	printf("? %d ", r - l + 1);
	for(int i = l; i <= r; i++) printf("%d ", i);
	puts("");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	if(x == sum[r] - sum[l - 1]) return ;
	int mid = l + r >> 1;
	Q(l, mid);
	Q(mid + 1, r);
}
int main(){
	//freopen("E.in", "r", stdin);
	//freopen("E.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		ok = 0;
		scanf("%d", &n);
		memset(sum, 0, sizeof(sum));
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
		int tmp = 1;
		while(n){
			int num = cal(n);
			Q(tmp, tmp + num - 1);
			//cout<< tmp << ' ' << tmp + num - 1 << endl; 
			n -= num; tmp += num;
		}
	}
	return 0;
}

