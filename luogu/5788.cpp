#include<bits/stdc++.h>
using namespace std;
const ll N=3e6+5;
struct Node{
  ll num,id;
}a[N];
ll ans[N];
stack<Node> q;
ll main(){
  freopen("5788.in","r",stdin);
  freopen("5788.out","w",stdout);
  ll n;
  scanf("%d",&n);
  for(ll i=1;i<=n;i++)scanf("%d",&a[i].num),a[i].id=i;
  for(ll i=1;i<=n;i++){
    while(q.size()){
      Node tmp=q.top();
      if(tmp.num>=a[i].num)
        break;
      else {
        ans[tmp.id]=a[i].id;
        q.pop();
      }
    }
    q.push(a[i]);
  }
  while(q.size()){
    ans[q.top().id]=0;
    q.pop();
  }
  for(ll i=1;i<=n;i++)prllf("%d ",ans[i]);
  return 0;
}