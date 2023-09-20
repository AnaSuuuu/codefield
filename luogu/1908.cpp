/*#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=5e5+5;
ll a[N],b[N];
ll c[N];
ll n;
ll lowbit(ll x){
  return x&(-x);
}
void add(ll x,ll y){
  for(ll i=x;i<=n;i+=lowbit(i))c[i]+=y;
}
ll query(ll x){
  ll ans=0;
  for(ll i=x;i;i-=lowbit(i))ans+=c[i];
  return ans;
}
ll main(){
  freopen("1908.in","r",stdin);
  freopen("1908.out","w",stdout);
  cin>>n;
  for(ll i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
  sort(a+1,a+1+n);
  ll tot=unique(a+1,a+1+n)-a-1;
  for(ll i=1;i<=n;i++)b[i]=lower_bound(a+1,a+1+tot,b[i])-a;
  ll ans=0;
  for(ll i=n;i>=1;i--){
    add(b[i],1);
    ans+=query(b[i]-1);
  }
  cout<<ans<<endl;
  return 0;
}*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll a[N],c[N];
ll ans;
ll n;
void msort(ll l,ll r){
  if(l==r)return ;
  ll mid=(l+r)>>1;
  msort(l,mid);
  msort(mid+1,r);
  ll b1=l,b2=mid+1;
  ll tmp=l;
  while(b1<=mid&&b2<=r){
    if(a[b1]>a[b2]){
      ans+=mid-b1+1;
      c[tmp++]=a[b2];
      b2++;
    }
    else {
      c[tmp++]=a[b1];
      b1++;
    }
  }
  while(b1<=mid){
    c[tmp++]=a[b1];
    b1++;
  }
  while(b2<=r){
    c[tmp++]=a[b2];
    b2++;
  }
  for(ll i=l;i<=r;i++)a[i]=c[i];
}
ll main(){
  freopen("1908.in","r",stdin);
  freopen("1908.out","w",stdout);
  cin>>n;
  for(ll i=1;i<=n;i++)cin>>a[i];
  msort(1,n);
  //for(ll i=1;i<=n;i++)cout<<a[i]<<' ';
  //cout<<endl;
  cout<<ans<<endl;
  return 0;
}