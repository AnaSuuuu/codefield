#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
  int n, maxn = 0, ans;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    if(a <= 10 && b > maxn) {
      maxn = b, ans = i;
    }
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