#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;

int n;
ll a, b, A, B, x, y, g, l;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x); 
    y -= (a / b) * x;
    return d;
}

void ExCRT() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%lld%lld", &A, &B);
    if(i == 1) {
      a = A;
      b = B;
    }
    else {
      g = exgcd(a, A, x, y);
      // cout << g << endl;
      if((B - b) % g) {
        printf("-1");
        return ;
      }
      x = x * ((B - b) / g);
      x = (x % (A / g) + (A / g)) % (A / g);
      l = A / g * a;
      // cout << l << ' ' << x << endl;
      b = ((a * x + b) % l + l) % l;
      a = l;
      // printf("%lld %lld\n", b, a);
    }
  }/**/
  //printf("1");
  //puts("AAA");
  printf("%lld\n", b % a);
}

int main(){
  // std::ios::sync_with_stdio(false);
  // std::cin.tie(nullptr);
  ExCRT();
  //printf("1");
  return 0;
}