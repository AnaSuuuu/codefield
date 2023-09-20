#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N];
int vis[N], okk[N];
int cal(int x){
	int num = 1;
	for(int i = 2; i <= x; i++) num *= i;
	return num;
}
int main(){
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n == 1)	{
			puts("1");
			continue;
		}
		if(n & 1){
			puts("-1");
			continue;
		}
		if(n == 2){
			puts("2 1");
			continue;
		}
		b[1] = 1, b[2] = 2, b[3] = 0, b[4] = 3;
 		for(int i = 5; i <= n; i++) {
 			if(i & 1) b[i] = n + 2 - b[i - 1];
 			else b[i] = b[i - 2] + 1;
		}
		//for(int i = 1; i <= n; i++) cout << b[i] << ' ';
		//cout << endl; 
		for(int i = 1; i <= n; i++){
			b[i]--;
			a[i] = b[i] - b[i - 1];
			a[i] = (a[i] + n) % n;
		}
		for(int i = 1; i <= n; i++)
			printf("%d ",a[i] == 0 ? n : a[i]);
		puts("");
	}
	return 0;
}

