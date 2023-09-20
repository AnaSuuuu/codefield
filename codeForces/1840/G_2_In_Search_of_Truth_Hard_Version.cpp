#include<bits/stdc++.h>
using namespace std;

const int mod = 1e6;
const int N = 1e6 + 5;
std::mt19937 mt_rand(time(0));

int num[N];
bool ok[N];

void solve() {
  int x, maxn;
  cin >> x;
  maxn = x;
  for(int i = 1; i <= 400; i++) {
    cout << "+ " << rand() % mod << endl;
    fflush(stdout);
    cin >> x;
    maxn = max(maxn, x);
  }
  ok[x] = 1;
  num[x] = 0;
  for(int i = 1; i < 300; i++) {
    cout << "+ 1" << endl;
    fflush(stdout);
    cin >> x;
    if(ok[x]) {
      cout<< "! " << i << endl;
      return ;
    }
    ok[x] = 1;
    num[x] = i;
  }
  int cnt = maxn + 299;
  cout << "+ " << maxn << endl;
  fflush(stdout);
  cin >> x;
  for(int i = 1; i <= 300; i++) {
    if(ok[x]) {
      cout << "! " << cnt - num[x] << endl;
      fflush(stdout);
      return ;
    }
    cnt += 300;
    cout << "+ 300" << endl;
    fflush(stdout);
    cin >> x;
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  solve();
  
  return 0;
}