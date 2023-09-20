#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5 + 5;
ll a[N], n, c[N << 2];

int lowbit(ll x) {
  return x & -x;
}
void add(ll x) {
  while(x <= n) {
    c[x]++;
    x += lowbit(x);
  }
}

ll query(ll x) {
  ll sum = 0;
  while(x) {
    sum += c[x];
    x -= lowbit(x);
  }
  return sum;
}

ll cal(ll x) {
  ll tmp = 1;
  while (tmp <= x) tmp *= 2;
  return tmp;
}

void solve() {
  ll x, tot = 0;
  cin >> n;
  x = cal(n); x--;
  for(int i = 1; i <= n; i++) c[i] = 0;
  for(int i = 1; i <= n; i++) cin >> a[i];
  if(n == 1) {
    cout << 0 << ' ' << 0 << endl;
    return ;
  }
  for(int i = 1; i <= n; i++) {
    tot += (a[i] - query(a[i]) - 1);
    add(a[i]);
    tot %= 2;
  }
  if(tot & 1) cout << 2 << ' ' << x << endl;
  else cout << 0 << ' ' << x - 2 << endl;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  } 
  return 0;
}