#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e4+5;
struct Node {
  ll p,c;
}s[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q1,q2;
priority_queue<ll,vector<ll>,greater<ll>>q3;
bool cmp(Node x,Node y){
  return x.c<y.c;
}
bool vis[N];
ll main(){
  freopen("3045.in","r",stdin);
  freopen("3045.out","w",stdout);
  ll n,k,m,sum=0;
  scanf("%lld%lld%lld",&n,&k,&m);
  for(ll i=1;i<=n;i++)scanf("%lld%lld",&s[i].p,&s[i].c);
  sort(s+1,s+1+n,cmp);
  for(ll i=1;i<=k;i++){
    sum+=s[i].c;
    vis[i]=1;
    if(sum>m){
      prllf("%d\n",i-1);
      return 0;
    }
    q3.push(s[i].p-s[i].c);
  }
  if(k==n){
    prllf("%d\n",n);
    return 0;
  }
  for(ll i=k+1;i<=n;i++){
    q1.push(make_pair(s[i].c,i));
    q2.push(make_pair(s[i].p,i));
  }
  for(ll i=k+1;i<=n;i++){
    while(vis[q1.top().second])q1.pop();
    while(vis[q2.top().second])q2.pop();
    pair<ll,ll> tmp1=q1.top();
    pair<ll,ll> tmp2=q2.top();
    ll tmp3=q3.top();
    if(tmp1.first+tmp3<tmp2.first){
      sum+=tmp1.first+tmp3;
      q1.pop();
      q3.pop();
      q3.push(s[tmp1.second].p-s[tmp1.second].c);
      vis[tmp1.second]=1;
    }
    else {
      sum+=tmp2.first;
      vis[tmp2.second]=1;
      q2.pop();
    }
    if(sum>m){
      prllf("%d\n",i-1);
      return 0;
    }
  }
  prllf("%lld\n",n);
  return 0;
}