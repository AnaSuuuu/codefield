#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		ll n;
		scanf("%lld", &n);
		cout << (n + 1) * (n + 1) + 1 << endl;
	}
	return 0;
}

