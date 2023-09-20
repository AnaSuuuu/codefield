#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N = 150005;
vector<int> a(N), b(N);

void init() {
  cin >> n;
  for(int i = 1; i <= (1 << n); i++) cin >> a[i];
  for(int i = 1; i <= (1 << n); i++) cin >> b[i];
  return ;
}

void solve() {
  
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  init();
  solve();
  return 0;
}