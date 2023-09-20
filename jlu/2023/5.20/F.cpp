#include<bits/stdc++.h>
using namespace std;
const int N = 105;
char s[N];
int main() {
  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);
  int t;
  cin >> t;
  while(t--){
    scanf("%s", s + 1);
    int ans = 0;
    int n = strlen(s + 1);
    if(n == 1 && s[1] == '^') {
      puts("1");
      continue;
    }
    for(int i = 1, j; i <= n; i = j) {
      j = i + 1;
      if(s[i] == '^') continue;
      for(; j <= n && s[j] == '_'; j++) ;
      int len = j - i;
      len = len - (s[i - 1] == '^') - (s[j] == '^');
      ans += len + 1;
      //cout << i << ' ' << j << endl;
    }
    cout << ans << endl;
  }  
  return 0;
}