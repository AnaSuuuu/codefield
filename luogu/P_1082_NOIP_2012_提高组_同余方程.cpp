#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
ll inv(ll a, ll p) {
    ll x, y;
    if (exgcd(a, p, x, y) != 1)
        return -1;
    return (x % p + p) % p;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll a, b;
  cin >> a >> b;
  cout << inv(a, b) << endl;
  return 0;
}