#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
  string s, a, b;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < 2 * n; ++i) {
	  a += "()"[i & 1];
	  b += ")("[i < n];
	}
  if(a.find(s) == string::npos) {
    cout << "YES\n" << a << endl;
    return ;
  } 
  else {
    if(b.find(s) == string::npos) {
      cout << "YES\n" << b << endl;
      return ;
    }
    else cout << "NO\n";
  }
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