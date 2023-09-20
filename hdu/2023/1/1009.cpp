#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  cout << ((m / n + (m % n != 0) >= d) ? "Yes" : "No") << endl;
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