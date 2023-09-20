#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
bool ok[N];
int num[N];

void solve() {
  int x, cnt = 0;
  cin >> x;
  num[x] = 0;
  ok[x] = 1;
  for(int i = 1; i <= 999; i++) {
    cout << "+ 1" << endl;
    fflush(stdout);
    cnt++;
    cin >> x;
    if(ok[x]) {
      cout << '!' << ' ' << cnt << endl;
      fflush(stdout);
      return ;
    }
    num[x] = cnt;
    ok[x] = 1;
  }
  for(int i = 1; i <= 1000; i++) {
    cnt += 1000;
    cout << "+ 1000" << endl;
    fflush(stdout);
    cin >> x;
    if(ok[x]) {
      cout << "! " << cnt - num[x] << endl;
      fflush(stdout);
      return ;
    }
  }/**/
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve(); 
  return 0;
}