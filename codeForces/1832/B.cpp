#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int a[N];
ll sum[N];
int main(){
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i]; 
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    ll ans = 0;
    for(int i = 0; i <= k; i++) {
      ans = max(ans, sum[n - (k - i)] - sum[i * 2]);
    }
    cout << ans << endl;
  }
  return 0;
}