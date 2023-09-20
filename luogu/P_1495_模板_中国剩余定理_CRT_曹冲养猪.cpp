#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 15;
ll a[N], b[N];

int exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x); 
    y -= (a / b) * x;
    return d;
}

void CRT() {
  ll n, M = 1, ans = 0;
  cin >> n; 
  for(int i = 1; i <= n; i++) {
    cin >> b[i] >> a[i];
    M *= b[i];
  }
  for(int i = 1; i <= n; i++) {
    ll m = M / b[i];
    ll x, y;
    exgcd(m, b[i], x, y);
    x = (x + b[i]) % b[i];
    x %= M;
    m *= x;
    m %= M;
    ans += a[i] * m % M;
    ans %= M;
  }
  cout << (ans % M + M) % M << endl;
  return ;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  CRT();
  return 0;
}