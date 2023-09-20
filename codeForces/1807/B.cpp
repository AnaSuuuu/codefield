#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		int n, num1 = 0, num2 = 0;
		int x;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> x;
			if(x & 1) num1 +=x;
			else num2 +=x;
		} 
		cout << (num2 > num1 ? "YES" : "NO") << endl;
	}
	return 0;
}

