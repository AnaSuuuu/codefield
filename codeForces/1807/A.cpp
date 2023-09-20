#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		int a, b, c;
		cin >> a >> b >> c;
		if(a + b == c) puts("+");
		else puts("-");
	}
	return 0;
}

