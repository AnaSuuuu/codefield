#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
char s[N];
vector<char> q;
int vis[N], cnt[N];
void pre(){
  cnt[1] = 1;
  for(int i = 2; i <= 2e5; i++){
    cnt[i] = 1 + cnt[i >> 1];
  }
}
int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int t;
	scanf("%d", &t);
	pre();
  //for(int i = 1; i <= 20 ; i++) cout << cnt[i] << ' ';
  //cout << endl;
  while(t--){
		q.clear();
		memset(vis, 0, sizeof(vis));
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		for(int i = 1; i <= n; i++) {
			if(!vis[s[i]]) {
				vis[s[i]] = 1;
				q.push_back(s[i]);
			}
		}
    int ans = 0x3f3f3f3f;
		for(char tmp: q){
      //cout << tmp << endl;
			int las = 0, Ans = 0;
			for(int i = 1; i <= n; i++){
				if(s[i] == tmp) {
          Ans = max(Ans, cnt[i - las - 1]), las = i;
          //puts("AAA");
          //cout << i - las - 1 << ' ' << cnt[i - las - 1] << endl;
          //las = i;
        }
			}
      Ans = max(Ans, cnt[n - las]);
      //cout << Ans << endl;
      ans = min(ans, Ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}

