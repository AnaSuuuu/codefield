#include <bits/stdc++.h>
typedef long long ll;

const int N = 105;
const int mod = 1e9 + 7;
struct Matrix {
  ll a[N][N];
} A, B;
ll n, k;

Matrix operator*(Matrix &x, Matrix &y) {
  Matrix c;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) c.a[i][j] = 0;
  for(int i = 1; i <= n; i++) 
    for(int j = 1; j <= n; j++) 
      for(int k = 1; k <= n; k++) {
        c.a[i][j] += (x.a[i][k] * y.a[k][j]) % mod;
        c.a[i][j] %= mod;
      }
  return c;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> k;
  for(int i = 1; i <= n; i++) 
    for(int j = 1; j <= n; j++) 
      std::cin >> A.a[i][j];
  for(int i = 1; i <= n; i++) B.a[i][i] = 1;
  while(k) {
    if(k & 1) B = A * B;
    A = A * A;
    k >>= 1;
  }
  for(int i = 1; i <= n; i++) 
    for(int j = 1; j <= n; j++)
      std::cout << B.a[i][j] << " \n"[j == n];
  return 0;
}