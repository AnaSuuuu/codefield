#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int cnt(int x){
	int num = 1;
	while(x){
		num *= x;
		x--;
	}
	return num;
}
int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n == 1) {
			puts("1");
			continue;
		}
		if((n + 1) % 2 == 0) {
			puts("-1");
			continue;
		}
		for(int i = 1; i * 2 <= n; i++) cout << 2 * i << ' ' << 2 * i - 1 << ' ';
		cout << endl;
	}
	return 0;
}

