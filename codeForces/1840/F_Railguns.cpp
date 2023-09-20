#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--) {
    int n, m, r;
    cin >> n >> m >> r;
    bool f[n + 1][m + 1][r + 1];
    bool is_ok[n + 1][m + 1][r + 1];
    for(int i = 0; i <= n; i++) 
      for(int j = 0; j <= m; j++)
        for(int k = 0; k <= r; k++)
          is_ok[i][j][k] = true;
    for(int i = 1; i <= r; i++) {
      int t, d, cod;
      cin >> t >> d >> cod;
      if(d == 1) {
        for(int j = 0; j <= m; j++) {
          if(0 <= t - cod - j && t - cod - j <= r) is_ok[cod][j][t - cod - j] = false; 
        }
      }
      else {
        for(int j = 0; j <= n; j++) {
          if(0 <= t - cod - j && t - cod - j <= r) is_ok[j][cod][t - cod - j] = false; 
        }
      }
    }
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= m; j++) {
        for(int k = 0; k <= r; k++) {
          if((i == 0) && (j == 0) && (k == 0)) f[i][j][k] = true;
          else f[i][j][k] = false;
          if(is_ok[i][j][k]) {
            if(i && f[i - 1][j][k]) f[i][j][k] = true;
            if(j && f[i][j - 1][k]) f[i][j][k] = true;
            if(k && f[i][j][k - 1]) f[i][j][k] = true;
          }
        }
      }
    }
    int ans = 0;
    for(int i = 0; i <= r; i++) {
      if(f[n][m][i]) {
        ans = n + m + i;
        break;
      }
    }
    cout << (ans != 0 ? ans : -1) << endl;
  } 
  return 0;
}