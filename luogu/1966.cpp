#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
const ll mod=1e8-3;
struct Node {
  ll num,id;
}a[N],b[N];
ll c[N],tr[N],n;
bool cmp(Node x,Node y){
  return x.num<y.num;
}
bool cmp1(Node x,Node y){
  return x.id<y.id;
}
ll lowbit(ll x){
  return x&(-x);
}
void add(ll x){
  for(ll i=x;i<=n;i+=lowbit(i)){
    tr[i]++;
  }
}
ll query(ll x){
  ll num=0;
  for(ll i=x;i;i-=lowbit(i)){
    num+=tr[i];
  }
  return num;
}
ll main(){
  freopen("1966.in","r",stdin);
  freopen("1966.out","w",stdout);
  scanf("%d",&n);
  for(ll i=1;i<=n;i++)scanf("%d",&a[i].num),a[i].id=i;
  for(ll i=1;i<=n;i++)scanf("%d",&b[i].num),b[i].id=i;
  sort(a+1,a+1+n,cmp);
  sort(b+1,b+1+n,cmp);
  for(ll i=1;i<=n;i++)a[i].num=i,b[i].num=i;
  sort(a+1,a+1+n,cmp1);
  sort(b+1,b+1+n,cmp1);
  for(ll i=1;i<=n;i++)c[a[i].num]=i;
  for(ll i=1;i<=n;i++)b[i].num=c[b[i].num];
  ll ans=0;
  for(ll i=1;i<=n;i++){
    ans+=(i-1)-query(b[i].num-1);
    ans%=mod;
    add(b[i].num);
  }
  cout<<ans<<endl;
  return 0;
}