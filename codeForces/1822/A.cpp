#include<bits/stdc++.h>
using namespace std;
const int N = 55;
int a[N], b[N];
int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int q;
	cin >> q;
	while(q--){
		int n, t;
		int ok = 0, ans = 0, id;
		cin >> n >> t;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> b[i];
		for(int i = 1; i <= n; i++){
			if(i + a[i] - 1 <= t && b[i] > ans) ans = b[i], ok = 1, id = i;
		}
		cout << (ok == 0 ? -1 : id) << endl;
	} 
	return 0;
}

