#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
bool vis[N];
int a[N], b[N];
std::set<int> q;
void in(int &x){
	x = 0;
	int f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	x *= f;
}
int main(){
	freopen("G.in", "r", stdin);
	freopen("G.out", "w", stdout);
	int T;
	in(T);
	while(T--){
		int n, ok = 1;
		in(n);
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++) in(a[i]);
		sort(a + 1, a + 1 + n);
		if(a[1] != 1){
			puts("NO");
			continue;
		}
		ll sum = a[1];
		for(int i = 2; i <= n; i++){
			if(sum < a[i]) {
				ok = 0;
				break;
			}
			sum += a[i];
		}
		if(ok) puts("YES");
		else puts("NO");
 	}	
	return 0;
}

