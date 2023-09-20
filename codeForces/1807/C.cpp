#include<bits/stdc++.h>
using namespace std;
int vis[30];
int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		string s;
		cin >> n;
		cin >> s;
		int ok = 1;
		memset(vis, -1, sizeof(vis));
		vis[s[0] - 'a'] = 1;
		for(int i = 1; i < n; i++){
			if(vis[s[i] - 'a'] == -1){
				vis[s[i] - 'a'] = 1 - vis[s[i - 1] - 'a'] ;
			}
			else if(vis[s[i] - 'a'] == vis[s[i - 1] - 'a']) {
				puts("NO");
				ok = 0;
				break;
			}
		}
		if(ok) puts("YES");
		//for(int i = 0; i < n; i++) cout << vis[s[i] - 'a'];
		//cout << endl;
	}
	return 0;
}

