#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1005;
int a[N];

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n, ans = 0, x;
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> x;
      ans ^= x;
    }
    cout << (ans ? "Yes" : "No") << endl; 
  } 
  return 0;
}