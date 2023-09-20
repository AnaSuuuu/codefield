#include<bits/stdc++.h>
using namespace std;
const ll N=105;
struct Node{
  ll y,m,d,id;
  char s[25];
}a[N];
bool cmp(Node x,Node y){
  return x.y==y.y?(x.m==y.m?(x.d==y.d?x.id>y.id:x.d<y.d):x.m<y.m):x.y<y.y;
}
ll main(){
  freopen("1104.in","r",stdin);
  freopen("1104.out","w",stdout);
  ll n;
  scanf("%d\n",&n);
  for(ll i=1;i<=n;i++)scanf("%s %d %d %d\n",a[i].s+1,&a[i].y,&a[i].m,&a[i].d),a[i].id=i;
  sort(a+1,a+1+n,cmp);
  for(ll i=1;i<=n;i++)prllf("%s\n",a[i].s+1);
  return 0;
}