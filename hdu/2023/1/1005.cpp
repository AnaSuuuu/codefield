#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 2e5 + 7;

int cnt[30], fa[N], k[N];
int n, m, q;
string s[N];
unsigned long long num[N];

int f(int x) {
  return (fa[x] == x ? x : (fa[x] = f(fa[x])));
}

bool judge(int a, int b) {
  int j = 0;
  for(int i = 1; i < m; i++) { // i 要从 2 开始，不然的话计算前缀函数会把自身也算上，变为 k[i] = i
    while(j && s[b][j] != s[b][i]) j = k[j];
    if(s[b][j] == s[b][i]) j++;
    k[i] = j;
  }
  j = 0;
  // for(int i = 0; i < m; i++) cout << k[i] << ' ';
  // cout << endl;
  for(int i = 0; i < m * 2; i++) {
    while(j && s[b][j] != s[a][i]) j = k[j];
    if(s[b][j] == s[a][i]) j++;
    // cout << j << endl;
    if(j == m) return true;;
  }
  return false;
}

void solve() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> s[i];
    for(int j = m; j < 2 * m; j++) s[i][j] = s[i][j - m];
    num[i] = 0; fa[i] = i;
    for(int j = 1; j <= 26; j++) cnt[j] = 0;
    for(int j = 0; j < m; j++) cnt[s[i][j] - 'a' + 1]++;
    for(int j = 1; j < m; j++) num[i] = 1ull * num[i] * 233 + cnt[j];
  }
  cin >> q;
  for(int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    if(num[x] != num[y]) {
      cout << "No" << endl;;
      continue;
    }
    if(fa[x] == fa[y]) {
      cout << "Yes" << endl;;
      continue;
    }
    if(judge(x, y)) {
      fa[x] = f(y);
      cout << "Yes" << endl;;
    }
    else cout << "No" << endl;;
  }
}

int main(){
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}