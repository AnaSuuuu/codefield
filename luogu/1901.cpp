#include<bits/stdc++.h>
using namespace std;
const ll N=1e6+5;
struct Node{
  ll h,v;
}a[N];
ll ans[N];
stack<Node>q;
ll main(){
  freopen("1901.in","r",stdin);
  freopen("1901.out","w",stdout);
  ll n;
  cin>>n;
  for(ll i=1;i<=n;i++)scanf("%d%d",&a[i].h,&a[i].v);
  for(ll i=1;i<=n;i++){
    while(q.size()){
      Node tmp=q.top();
      if(tmp.h>=a[i].h)
        break;
      else {
        ans[i]+=tmp.v;
        q.pop();
      }
    }
    q.push(a[i]);
  }
  while(q.size())q.pop();
  for(ll i=n;i>=1;i--){
    while(q.size()){
      Node tmp=q.top();
      if(tmp.h>=a[i].h)
        break;
      else {
        ans[i]+=tmp.v;
        q.pop();
      }
    }
    q.push(a[i]);
  }
  sort(ans+1,ans+1+n);
  cout<<ans[n]<<endl;
  return 0;
}