#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5 + 5;

struct Node {
  ll a, b;
} s[N];
int n;

bool cmp(Node x, Node y) {
  return x.a + x.b > y.a + y.b;
}

void solve() {
  ll ans = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> s[i].a >> s[i].b;
  sort(s + 1, s + 1 + n, cmp);
  for(int i = 1; i <= n; i++) {
    if(i & 1) ans += s[i].a;
    else ans -= s[i].b;
    // cout << ans << endl;
  }
  cout << ans << endl;
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