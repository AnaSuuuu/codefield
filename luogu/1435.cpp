#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
char s[N];
int f[N][N];
int main(){
  freopen("1435.in", "r", stdin);
  freopen("1435.out", "w", stdout);
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  memset(f, 0x3f, sizeof(f));
  for(int i = 1; i <= n; i++) f[i][i] = 0, f[i][i - 1] = 0;
  for(int len = 1; len < n; len++){
    for(int i = 1; i + len <= n; i++){
      int j = i + len;
      f[i][j] = min(f[i][j], min(f[i + 1][j] + 1, f[i][j - 1] + 1));
      if(s[i] == s[j]) f[i][j] = min(f[i][j], f[i + 1][j - 1]);
      else f[i][j] = min(f[i][j], f[i + 1][j - 1] + 2);
    }
  }
  cout << f[1][n] << endl;
  return 0;
}