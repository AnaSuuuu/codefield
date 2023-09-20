#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 50005;
int f[N], a[N];
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    f[1] = a[1], f[2] = a[2];
    for(int i = 1; i <= n; i++) {
      f[i] = min(f[i - 1], f[i - 2]) + a[i];
    }
    cout << min(f[n], f[n - 1]) << endl;
    // for(int i = 1; i <= n; i++) cout << f[i] << ' ';

  } 
  return 0;
}