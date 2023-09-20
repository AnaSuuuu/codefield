#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll a[N];
int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + 1 + n);
		if(n == 1) cout << a[1] << endl;
		else cout << max(a[1] * a[2], a[n] * a[n - 1]) << endl;
	}	
	return 0;
}

