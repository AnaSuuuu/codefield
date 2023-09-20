#include<bits/stdc++.h>
using namespace std;
const int N = 35;
int a[N], f[N][N], root[N][N];
void out(int l, int r){
  cout << root[l][r] << ' ';
  if(root[l][r] > l)out(l, root[l][r] - 1);
  if(root[l][r] < r)out(root[l][r] + 1, r);
}
int main(){
  freopen("1040.in", "r", stdin);
  freopen("1040.out", "w", stdout);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> f[i][i], root[i][i] = i;
  for(int len = 1; len < n; len++){
    for(int i = 1; i + len <= n; i++){
      int j = i + len;
      f[i][i - 1] = 1; f[j + 1][j] = 1;
      for(int k = i; k <= j; k++){
        if(f[i][k - 1] * f[k + 1][j] + f[k][k] > f[i][j]){
          f[i][j] = f[i][k - 1] * f[k + 1][j] + f[k][k];
          root[i][j] = k;
        }
      }
      //if(1 * f[i + 2][j] + f[i + 1][i + 1])
    }
  }
  //cout << f[1][4] << endl;
  cout << f[1][n] << endl;
  out(1, n);
  return 0;
}