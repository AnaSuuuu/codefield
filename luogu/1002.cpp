#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 25;
const int zh[][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
ll vis[N][N], f[N][N];
int main(){
  freopen("1002.in", "r", stdin);
  freopen("1002.out", "w", stdout);
  int a1, a2, b1, b2;
  cin >> a1 >> b1 >> a2 >> b2;
  a1++, a2++, b1++, b2++;
  for(int i = 0; i < 8; i++){
    int dx = a2 + zh[i][0], dy = b2 + zh[i][1];
    if(dx < 1 || dx > a1 || dy < 1 || dy > b1) continue;
    vis[dx][dy] = 1;
  }
  vis[a2][b2] = 1;
  f[1][1] = 1;
  for(int i = 1; i <= a1; i++){
    for(int j = 1; j <= b1; j++) {
      if(i == 1 && j == 1) continue;
      if(vis[i][j]) continue;
      f[i][j] = f[i - 1][j] + f[i][j - 1];
    }
  }
  printf("%lld\n", f[a1][b1]);
  return 0;
}