#include<bits/stdc++.h>
using namespace std;
const ll N=8e6+5;
ll a[N];
queue<ll>q0,q1,q2;
bool cmp(ll x,ll y){
  return x>y;
}
ll main(){
  freopen("2827.in","r",stdin);
  freopen("2827.out","w",stdout);
  ll n,m,q,u,v,t;
  cin>>n>>m>>q>>u>>v>>t;
  for(ll i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+1+n);
  for(ll i=n;i>=1;i--)q0.push(a[i]);
  ll att=0;
  double p=(double)u/v;
  if(m>=1){
    att=q;
    
    q1.push(floor(p*(double)q0.front())-att);
    q2.push(q0.front()-floor(p*(double)q0.front())-att);
    if(t==1)cout<<q0.front()<<' ';
    q0.pop();
  }
  for(ll i=2;i<=m;i++){
    ll tmp;
    if(q0.size()){
      if(q0.front()>q1.front()&&q0.front()>q2.front()){
        tmp=q0.front();
        q0.pop();
      }
      else if(q1.front()>=q0.front()&&q1.front()>=q2.front()){
        tmp=q1.front();
        q1.pop();
      }
        else {
          tmp=q2.front();
          q2.pop();
        }
      }
    else {
      if(q1.front()>q2.front()){
        tmp=q1.front();
        q1.pop();
      }
      else {
        tmp=q2.front();
        q2.pop();
      }
    }
    tmp+=att;att+=q;
    if(i%t==0)cout<<tmp<<' ';
    q1.push(floor(p*(double)tmp)-att);
    q2.push(tmp-floor(p*(double)tmp)-att);
  }
  ll tot=0;
  while(q0.size()){
    a[++tot]=q0.front();
    q0.pop();
  }
  while(q1.size()){
    a[++tot]=q1.front();
    q1.pop();
  }
  while(q2.size()){
    a[++tot]=q2.front();
    q2.pop();
  }
  sort(a+1,a+1+n+m,cmp);
  puts("");
  for(ll i=t;i<=n+m;i+=t)cout<<a[i]+att<<' ';
  return 0;
}