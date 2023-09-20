#include<bits/stdc++.h>
using namespace std;
const int N = 55;
bool vis[1005];
char s[N];
int main(){
  int t;
  cin >> t;
  while(t--) {
    int n, ans = 0;
    scanf("%d", &n);
    scanf("%s", s + 1);
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i <= n; i++) {
      int num = (s[i - 1] - 'a') * 7 + s[i] - 'a';
      if(vis[num] == 0) ans++;
      vis[num] = 1; 
    }
    cout << ans << endl;
  }
  return 0;
}