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
    string s;
    cin >> s;
    for(int i = 0; i < n;) {
      cout << s[i]; i++; 
      char tmp = s[i - 1];
      while(s[i] != tmp) {
        i++;
      }
      i++;
    }
    cout << endl;
  } 
  return 0;
}