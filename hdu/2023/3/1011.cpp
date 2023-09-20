#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 55;
string s[N];
void solve() {
  int n, z;
  cin >> n >> z;
  for(int i = 1; i <= n; i++) cin >> s[i];
  if(n * z % 100) {
    cout << "error\n";
    return ;
  }
  for(int i = 1; i <= n; i++) {
    int tmp = 0;
    for(int j = 0; j < n; j++) {
      // cout << tmp << ' ' << s[i][j] << endl;
      if(j == 0 || tmp == 0 || s[i][j] == s[i][j - 1]) tmp++;
      else {
        if(tmp * n * z / 100 % n) {
          cout << "error\n";
          return ;
        }
        tmp = 1;
      }  
    }
    
    if(tmp) {
      // cout << tmp << endl;
        if(tmp * n * z / 100 % n) {
          cout << "error\n";
          return ;
        }
        tmp = 0;
      }
  }
  for(int j = 0; j < n; j++) {
    int tmp = 0;
    for(int i = 1; i <= n; i++) {
      if(i == 1 || tmp == 0 || s[i][j] == s[i - 1][j]) tmp++;
      else {
        if(tmp * n * z / 100 % n) {
          cout << "error\n";
          return ;
        }
        tmp = 1;
      }  
    }
    if(tmp) {
        if(tmp * n * z / 100 % n) {
          cout << "error\n";
          return ;
        }
        tmp = 0;
      }
  }
  // cout << round(100 / z) << endl;
  for(int i = 1; i <= n * z / 100; i++) {
    for(int j = 1; j <= n * z / 100; j++) {
      // cout << '(' <<  round(i * 100.0 / z) << ' ' << round(j * 100.0 / z) - 1 << ')' << endl;
      cout << s[(int) ceil(i * 100.0 / z)][(int) ceil(j * 100.0 / z) - 1];
    }
    cout << endl;
  }
  return ;
}
int main(){
  freopen("1011.in", "r", stdin);
  freopen("1011.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  } 
  return 0;
}