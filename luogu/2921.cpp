#include<bits/stdc++.h>
using namespace std;
const ll N=1e6+5;
ll ans[N],t[N];
ll ste[N];//表示每一轮中第几步到达i点
bool vis[N];//标记这个点前几轮是否访问过
ll main(){
  freopen("2921.in","r",stdin);
  freopen("2921.out","w",stdout);
  ll n;
  cin>>n;
  for(ll i=1;i<=n;i++)cin>>t[i];
  for(ll i=1;i<=n;i++){
    if(ans[i])continue;
    stack<ll> q;
    ll kdl=0,tmp=i;
    while(ste[tmp]==0){
      ste[tmp]=++kdl;
      q.push(tmp);
      tmp=t[tmp];
    }
    if(vis[tmp]){
      ll kk=1;
      while(q.size()){
        ans[q.top()]=ans[tmp]+kk;
        vis[q.top()]=1;
        q.pop();
        kk++;
      }
    }
    else {
      while(q.top()!=tmp){
        ans[q.top()]=kdl-ste[tmp]+1;
        vis[q.top()]=1;
        q.pop();
      }
      ans[tmp]=kdl-ste[tmp]+1;
      vis[tmp]=1;
      q.pop();
      ll kk=1;
      while(q.size()){
        ans[q.top()]=ans[tmp]+kk;
        vis[q.top()]=1;
        q.pop();
        kk++;
      }
    }
  }
  for(ll i=1;i<=n;i++)cout<<ans[i]<<endl;
  return 0;
}