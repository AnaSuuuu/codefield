#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll A, X, M;
void Exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) x = 1, y = 0;
  else Exgcd(b, a % b, y, x), y -= a / b * x;
}
ll qmul(ll x,ll y){
  ll tmp = 1;
  while(x){
    if(x & 1){
      tmp = (tmp * y) % M;
    }
    y *= y;
    y %= M;
    x /= 2;
  }
  return tmp;
}
int main() {
  freopen("E.in","r",stdin);
  freopen("E.out","w",stdout);
  scanf("%lld%lld%lld", &A, &X, &M);
  ll x, y;
  Exgcd (A - 1, M, x, y);
  x = (x % M + M) % M;
  printf("%lld\n", (qmul(X, A) % M - 1 + M) % M * x % M);
  //printf ("%d\n", x); //x是a在mod p下的逆元
}