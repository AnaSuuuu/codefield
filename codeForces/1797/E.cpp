#include<bits/stdc++.h>
#define ls root<<1
#define rs root<<1|1
using namespace std;
const int N = 1e5 + 5;
const int M = 5e6 + 5;
int n, m, a[N], phi[M];
int pri[M], fac[M], tot;
int dis[M], fa[M][6];
void pre(){
  phi[1] = 1;
  for(int i = 2; i <= 5e6; i++){
    if(fac[i] == 0){
      fac[i] = i;
      pri[++tot] = i;
      phi[i] = i - 1;
    }
    for(int j = 1; j <= tot; j++){
      if(pri[j] > fac[i] || pri[j] * i > 5e6) break;
      fac[pri[j] * i] = pri[j];
      if(pri[j] == fac[i]) phi[i * pri[j]] = pri[j] * phi[i];
      else phi[i * pri[j]] = (pri[j] - 1) * phi[i];
    }
  }
  return ;
}
void pre1(){
  dis[1] = 1;
  for(int i = 0; i <= 5; i++) fa[1][i] = 1;
  for(int i = 2; i <= 5e6; i++){
    fa[i][0] = phi[i];
    dis[i] = dis[phi[i]] + 1;
    for(int j = 1; j <= 5 ; j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
  }
  return ;
}
int LCA(int u, int v){
  if(dis[u] < dis[v]) u ^= v ^= u ^= v;
  for(int i = 5; i >= 0; i--){
    if(dis[fa[u][i]] >= dis[v]) u = fa[u][i];  
  }
  if(u == v) return u;
  for(int i = 5; i >= 0; i--)
    if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
struct SegmentTree{
  struct Node{
    int lca, mndis, is_one, ans;
  }tr[N<<2];
  void pushup(int root, int l, int r){
    int mid = l + r >> 1;
    tr[root].lca = LCA(tr[ls].lca, tr[rs].lca);
    tr[root].is_one = tr[ls].is_one & tr[rs].is_one;
    tr[root].ans = tr[ls].ans + tr[rs].ans + (mid - l + 1) * (dis[tr[ls].lca] - dis[tr[root].lca]) + (r - mid) * (dis[tr[rs].lca] - dis[tr[root].lca]);
    tr[root].mndis = min(tr[ls].mndis, tr[rs].mndis);
    return ;
  }
  void build(int root, int l, int r){
    if(l == r){
      tr[root].lca = a[l];
      tr[root].is_one = a[l] == 1;
      tr[root].ans = 0;
      tr[root].mndis = dis[a[l]];
      return ;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(root, l, r);
    return ; 
  }
  void modify(int root, int l, int r, int nl, int nr){
    if(tr[root].is_one) return ;  
    if(l == r){
      tr[root].lca = fa[tr[root].lca][0];
      tr[root].mndis--;
      tr[root].is_one = tr[root].lca == 1;
      return ;
    }
    int mid = l + r >> 1;
    if(mid >= nl) modify(ls, l, mid, nl, nr);
    if(mid + 1 <= nr) modify(rs, mid + 1, r, nl, nr);
    pushup(root, l, r);
    return ;
  }
  int query_lca(int root, int l, int r, int nl, int nr){
    if(l >= nl && r <= nr) return tr[root].lca;
    int mid = l + r >> 1;
    if(mid < nl) return query_lca(rs, mid + 1, r, nl, nr);
    if(mid + 1 > nr) return query_lca(ls, l, mid, nl, nr);
    return LCA(query_lca(ls, l, mid, nl, nr), query_lca(rs, mid + 1, r, nl, nr));
  }
  int query_ans(int root, int l, int r, int nl, int nr, int lca){
    if(l >= nl && r <= nr) return tr[root].ans + (r - l + 1) * (dis[tr[root].lca] - dis[lca]);
    int mid = l + r >> 1, ans = 0;
    if(mid >= nl) ans += query_ans(ls, l, mid, nl, nr, lca);
    if(mid + 1 <= nr) ans += query_ans(rs, mid + 1, r, nl, nr, lca);
    return ans;
  }
}T;
int main(){
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  pre();
  pre1();
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
  T.build(1, 1, n);
  while(m--){
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    switch(t){
      case 1:{
        T.modify(1, 1, n, l, r);
        break;
      }
      case 2:{
        int lca = T.query_lca(1, 1, n, l, r);
        printf("%d\n", T.query_ans(1, 1, n, l, r, lca));
        break;
      }
    }
  }
  //cout << T.query_lca(1, 1, n, 3, 4) << endl;
  return 0;
}
