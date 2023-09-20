#include<bits/stdc++.h>
using namespace std;

const int N = 55;
long double x[N], y[N];
struct Node {
  long double x, y;
} s[N], ans[N];

bool cmp(Node a,Node b) {
  return a.x < b.x;
}

void solve() {
  int n;
  double tmp;
  cin >> n;
  cout << "? 0 1 0" << endl;
  fflush(stdout);
  for(int i = 1; i <= n; i++) {
    cin >> x[i] >> tmp;
  }
  sort(x + 1, x + 1 + n);
  cout << "? 1 0 0" << endl;
  fflush(stdout);
  for(int i = 1; i <= n; i++) {
    cin >> tmp >> y[i] ;
  }
  sort(y + 1, y + 1 + n);
  cout << "? -0.001 1 0" << endl;
  fflush(stdout);
  for(int i = 1; i <= n; i++) 
    cin >> s[i].x >> s[i].y;
  sort(s + 1, s + 1 + n, cmp);
  for(int i = 1; i <= n; i++) {
    tmp = -1000.0 * (x[i] - s[i].x) + s[i].y;
    ans[i].x = x[i];
    double minn = 2000000000.0;
    for(int j = 1; j <= n; j++) {
      if(fabs(y[j] - tmp) < minn) {
        minn = fabs(y[j] - tmp);
        ans[i].y = y[j];
      }
    }
  }
  cout << "! ";
  for(int i = 1; i <= n; i++) {
    cout << ans[i].x << ' ' << ans[i].y << ' ';
  }
  cout << endl;
  fflush(stdout);
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}