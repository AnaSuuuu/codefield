#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N], k, n, q;
int lowbit(int x) {return x & (-x);}
map<int, int> M;
bool judge(int lim) {
  int kdl = 0, sum = 0, maxn = 0;
  M.clear();
  for(int i = 1; i <= n; i++) {
    if(a[i] >= lim && kdl <= k) return true;
    if(a[i] < lim) {
      int pos = lim - a[i];
      while(pos <= k && M[pos] == 1) pos++;
      if(pos <= k) M[pos] = 1;
      else return false;
      kdl++; sum += a[i];
      if(kdl > k) return false;
    }
  }
  if(k & 1) {
    if((sum + (lim + lim - n + 1) * n / 2 - lim * n) * 2 + kdl >= k) return true;
    else return false;
  }
  else {
    if((sum + (lim + lim - n + 1) * n / 2 - lim * n) * 2 + kdl > k - 1) return true;
    else return false;
  }
}
int main(){
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int l = 0x3f3f3f3f, r = 0;
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    l = min(l, a[i]);
    r = max(r, a[i]);
  }
  r++;
  sort(a + 1, a + 1 + n);
  for(int i = 1; i <= q; i++) {
    cin >> k;
    int dl = l, dr = max(r, l + k), ans;
    //cout << dl << ' ' << dr << endl;
    cout << judge(11) << endl;
    while(dr >= dl) {
      int mid = dl + dr >> 1;
      if(judge(mid)){
        ans = mid;
        dl = mid + 1;
      }
      else dr = mid - 1;
    }
    cout << ans << ' ';
  }
  return 0;
}