#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 2e5 + 5;
int a[N];

void solve() {
  int n, k, ans = 0, tmp = 0;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 +n);
  for(int i = 2; i <= n; i++) {
    if(abs(a[i] - a[i - 1]) <= k) tmp++;
    else {
      ans = max(ans, tmp);
      tmp = 0;
    }
  }
  ans = max(ans, tmp);
  cout << n - ans - 1 << endl;
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