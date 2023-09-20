#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int a, b;
  cin >> a >> b;
  if(max(a, b) - min(a, b) > 1) cout << "1" << endl; 
  else cout << "0\n";
  return 0;
}