#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 5005;
const int M = 505;

int p[N], n, m;
ll ans[N], maxn;
bitset<N> rel[N];

struct Node {
  int val, id;
} s[N];

bool cmp(Node x, Node y) {
  return x.val < y.val;
}

void dfs(int u) {
  if(ans[u]) return ;
  for(int i = 1; i <= n; i++) {
    if(rel[u][i]) {
      dfs(i);
      ans[u] = max(ans[u], ans[i]);
    }
  }
  ans[u] += p[u];
  return ;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> m >> n;
  for(int i = 1; i <= n; i++) cin >> p[i], rel[i].set();
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> s[j].val;
      s[j].id = j;
    }
    bitset<N> ok;
    ok.set();
    sort(s + 1, s + 1 + n, cmp);
    int j = 1; 
    while(j <= n) {
      int k = j;
      for(; k <= n && s[j].val == s[k].val; k++);
      for(int u = j; u < k; u++) ok[s[u].id] = false;
      while(j < k) rel[s[j++].id] &= ok;
    }
  }
  for(int i = 1; i <= n; i++) {
      dfs(i);
      maxn = max(maxn, ans[i]);
    }
    cout << maxn << endl;
  return 0;
}