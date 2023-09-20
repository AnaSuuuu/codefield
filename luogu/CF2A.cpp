#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
map<string, int> M, MM;
set<string> q;
string s[N];
int num[N];
int main(){
	freopen("CF2A.in", "r", stdin);
	freopen("CF2A.out", "w", stdout);
	int n, ans = 0, pos = 0x3f3f3f3f;
	string name;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i] >> num[i];
		M[s[i]] += num[i];
		//if(M[s[i]] > ans) ans = M[s[i]];
		q.insert(s[i]);
	}
	for(set<string>::iterator it = q.begin(); it != q.end(); ++it){
		//cout << *it << ' ' << M[*it] << endl;
		if(M[*it] > ans) ans = M[*it];
	}/**/
	//cout << ans << endl;
	for(int i = 1; i <= n; i++){
		MM[s[i]] += num[i];
		if(MM[s[i]] >= ans && M[s[i]] == ans){
			cout << s[i];
			return 0; 
		}
	}
	return 0;
}

