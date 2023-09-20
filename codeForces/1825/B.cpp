#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll a[N];
int main(){
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int t;
  scanf("%d", &t);
  while(t--){
    ll n, m;
    scanf("%lld%lld", &n, &m);
    if(n > m) n ^= m ^= n ^= m;
    for(int i = 1; i <= n * m; i++)
      scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n * m);
    cout << (n * m - n) * (a[n * m] - a[1]) + max((n - 1) * (a[n * m] - a[2]), (n - 1) * (a[n * m - 1] - a[1])) << endl;
  }
  return 0;
}