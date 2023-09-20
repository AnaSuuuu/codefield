#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
  for(int i = 1; i <= 8; i++) {
    for(int j = 1; j <= 8; j++) {
      char c;
      cin >> c;
      if(c != '.') cout << c;
    }
  }
  cout << endl;
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