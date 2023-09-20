#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5 + 5;
ll a[N];

void solve() {
  ll n, ans = 0;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) ans += a[i] * a[j]; 
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