#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1005;
int a[N], n;
double cal(int x) {
  double num1 = x, num2 = 0;
  num1 = (double) num1 / n;
  for(int i = x + 1; i <= n; i++) {
    num2 += (double) 1 / (i - 1);
  }
  num1 *= num2;
  return num1;
}

void solve() {
  cin >> n;
  if(n == 2) {
    cout << 0 << endl;
    return ;
  }
  if(int(n / exp(1)) == round(n / exp(1))) {
    cout << int(n / exp(1)) << endl;
    return ;
  }
  int a = int(n /exp(1)), b = round(n / exp(1));
  // cout << a << ' ' << b << endl;
  if(cal(a) > cal(b)) cout << a << endl;
  else cout << b << endl;
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