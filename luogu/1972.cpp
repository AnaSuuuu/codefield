#include<bits/stdc++.h>
using namespace std;
const ll N = 1e6 + 5;
ll a[N], c[N], pos[N], n;
struct Node{
  ll l, r, ans, id;
}q[N];
inline void in(ll &x){
  x = 0;
  ll f = 1;
  char c = getchar();
  while(c < '0' || c > '9'){
    if(c == '-')f = -1;
    c = getchar();
  }
  while(c >= '0' && c <= '9'){
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  x *= f;
}
bool cmp(Node x,Node y){
  return x.r < y.r;
}
inline ll lowbit(ll x){
  return x & (-x);
}
void add(ll x, ll num){
  for(; x <= n; x += lowbit(x))c[x] += num;
}
inline ll query(ll x){
  ll sum = 0;
  for(; x; x -= lowbit(x))sum += c[x];
  return sum;
}
bool cmp1(Node x,Node y){
  return x.id < y.id;
}
ll main(){
  freopen("1972.in","r",stdin);
  freopen("1972.out","w",stdout);
  in(n);
  for(ll i = 1; i <= n; i++)in(a[i]);
  ll m;
  in(m);
  for(ll i = 1; i <= m; i++){
    in(q[i].l);
    in(q[i].r);
    q[i].id = i;
  }
  sort(q + 1, q + 1 + m, cmp);
  ll cnt = 1;
  for(ll i = 1; i <= m; i++){
    for(; cnt <= q[i].r; cnt++){
      if(pos[a[cnt]] != 0)
        add(pos[a[cnt]], -1);
      add(cnt, 1);
      pos[a[cnt]] = cnt;/**/
    }
    q[i].ans = query(q[i].r) - query(q[i].l - 1);
  }/**/
  sort(q + 1, q + 1 + m, cmp1);
  for(ll i = 1;i <= m; i++)
    prllf("%d\n", q[i].ans);
  return 0;
}