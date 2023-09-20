#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 50005;

struct Node {
  ll a, b, g;
} s[N];
map<ll, int> m;

void in(ll &x) {
  x = 0;
  char c = getchar();
  while(c > '9' || c < '0') {
    c = getchar();
  }
  while(c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
}

ll gcd(ll a, ll b) {
  return (a % b == 0 ? b : gcd(b, a % b));
}
bool check(ll x, ll y, ll q, ll e)
{
	if(x > q || y > e) return 0;
	while(x < q && y < e && e && q)
	{
		if(q > e) q %= e;
		else e %= q;
	}
	if(q == 0) q = e;
	if(e == 0) e = q;
	if(x != q && y != e) return 0;
	if(x == q)
	{
		int now = e - y;
		if(now % x == 0) return 1;
		else return 0;
	}
	if(y == e)
	{
		int now = q - x;
		if(now % y == 0) return 1;
		else return 0;
	}
	return 0;
}
bool cmp(Node x, Node y) {
  return x.g < y.g;
}
void solve() {
  m.clear();
  ll n, q;
  in(n), in(q);
  for(int i = 1; i <= n; i++) {
    in(s[i].a), in(s[i].b);
    s[i].g = gcd(s[i].a, s[i].b);
    m[s[i].g]++;
  }
  sort(s + 1, s + 1 + n, cmp);
  /* for(int i = 1; i <= n; i++) {
    cout << s[i].a << ' ' << s[i].b << endl;
  } */
  for(int i = 1; i <= q; i++) {
    ll A, B;
    in(A), in(B);
    ll G = gcd(A, B);
    if(m[G] == 0) {
      cout << "0\n";
      continue;
    }
    else {
      int l = 1, r = n, cho = 0, ans = 0;
      while(l <= r) {
        int mid = l + r >> 1;
        if(s[mid].g < G) {
          cho = mid;
          l = mid + 1;
        }
        else r = mid - 1;
      }
      // cout << cho << endl;
      for(int j = cho + 1; s[j].g == G; j++) {
        // cout << "AAA" << endl;
        if(check(A, B, s[j].a, s[j].b)) ans++;
      }
      cout << ans << endl;
    } 
    /* cout << m[G] << endl;*/
  }
  return ;
}

int main(){
  freopen("1012.in", "r", stdin);
  freopen("1012.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll t;
  in(t);
  while(t--) {
    solve();
  } 
  return 0;
}