#include<bits/stdc++.h>
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cout << (i << 1) << ' ';
    cout << endl;
  } 
  return 0;
}