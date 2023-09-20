#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 3e5 + 5;
ll a[N], n, k, num[N];

bool check(ll lim) {
  priority_queue<ll> q;
  ll s = 0;
  for(int i = 1; i <= n; i++) {
    s += a[i];
    q.push(a[i]);
    while(s > lim) s -= q.top(), q.pop(); 
    num[i] = q.size();
  }
  s = 0;
  while(q.size()) q.pop();
  for(int i = n; i >= 1; i--) {
    s += a[i];
    q.push(a[i]);
    while(s > lim) s -= q.top(), q.pop(); 
    if(num[i - 1] + q.size() >= k) return true;
  }
  return false;
}

void solve() {
  ll l = 0, r = 0, ans;
  std::cin >> n >> k;
  for(int i = 1; i <= n; i++) std::cin >> a[i], r += a[i];
  //cout << l << ' ' << r << endl;
  while(r >= l) {
    ll mid = l + r >> 1;
    if(check(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  cout << ans << endl;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while(t--) {
    solve();
  }
  
  return 0;
}