#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int ans = 1;
		if(s.size() == 1 && s[0] == 0){
			puts("0");
			continue;
		}
		if(s[0] == '?')ans = 9;
		if(s[0] == '0'){
			puts("0");
			continue;
		}
		//cout << s[1] << endl;
		for(int i = 1; i < s.size(); i++) if(s[i] == '?') ans *= 10;
		cout << ans << endl;
	}
	return 0;
}

