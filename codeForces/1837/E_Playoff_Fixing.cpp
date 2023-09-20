#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 19;
const int mod = 998244353;
ll a[(1 << N) + 5], n;

ll cal1(ll x) {
  ll num = 1;
  while(x) {
    num *= x;
    num %= mod;
    x--;
  }
  return num % mod;
}

ll cal2(ll x) {
  ll num = 1;
  while(x) {
    num *= 2;
    num %= mod;
    x--;
  }
  return num % mod;
}
ll solve(vector <int> q) {
  if(n == 1) return 1;
  vector <int> p;
  int cnt1 = 0, cnt2 = 0;
  //cout << n << "BBB" << endl;
  for(int i = 0; i < n; i += 2) {
    if(q[i] != -1 && q[i + 1] != -1) {
      if((q[i] > n / 2) == (q[i + 1] > n / 2)) {
        //cout << "AAA" << endl;
        return 0;
      }
      else p.push_back(min(q[i], q[i + 1]));
    }
    else {
      if(q[i] == -1 && q[i + 1] == -1) cnt1++, cnt2++, p.push_back(-1);
      else {
        if(q[i] > n / 2 || q[i + 1] > n / 2) p.push_back(-1);
        else p.push_back(max(q[i], q[i + 1])), cnt2++;
      }
    }
  }  
  n /= 2;
  //cout << n << endl;
  //cout <<  cnt1 << ' ' << cnt2 << endl;
  return cal2(cnt1) * cal1(cnt2) % mod * solve(p) % mod;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  vector <int> q;
  int k;
  cin >> k;
  n = (1 << k);
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    q.push_back(x);
  }
  cout << solve(q) << endl;;
  return 0;
}