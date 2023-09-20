#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N];

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    memset(a, 0, sizeof(a));
    int n, k, tmp = 0, ans = 0;
    cin >> n >> k >> tmp;
    for(int i = 2; i <= n; i++) {
      int x;
      cin >> x;
      a[i] = -abs(x - tmp);
      ans += abs(x - tmp);
      tmp = x;
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i < k; i++) ans += a[i];
    cout << ans << endl;
  }
  return 0;
}