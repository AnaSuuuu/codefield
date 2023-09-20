#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];
bool p[N];

int lowbit(int x) {
  return x & (-x);
}

int cal(int x) {
  while(x > lowbit(x)) {
    x -= lowbit(x);
  }
  int cnt = 0;
  while(x) {
    x >>= 1;
    cnt++;
  }
  return (1 << (cnt)) - 1;
}

void work(){
  int n, tmp = 0, maxn = 0;
  memset(p, 0, sizeof(p));
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i], maxn = max(maxn, a[i]);
  for(int i = 1; i <= n; i++) {
    tmp ^= a[i];
    maxn = max(maxn, tmp);
    p[tmp] = 1;
  }
  if(cal(maxn) == maxn) {
    cout << maxn << endl;
    return ;
  }
  for(int i = cal(maxn); i > maxn; i--) {
    int tmp = a[1];
    for(int j = 2; j <= n; j++) {
      if(p[i ^ tmp]) {
        cout << i << endl;
        return ;
      }
      tmp ^= a[j];
    }
    if(p[i ^ tmp]) {
      cout << i << endl;
      return ;
    }
  }
  cout << maxn << endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin>>t;
  //cout << cal(8) << endl;
  while(t--) {
    work();
  }
}