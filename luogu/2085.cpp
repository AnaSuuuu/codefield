#include<bits/stdc++.h>
using namespace std;
const ll N=1e4+5;
struct Node{
  ll a,b,c;
}s[N];
struct node{
  ll id,op,num,x;
  friend bool operator < (node x,node y) {
    return x.num>y.num;//按照升序排列
  }
};
priority_queue<node>q;
ll main(){
  freopen("2085.in","r",stdin);
  freopen("2085.out","w",stdout);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=n;i++){
    cin>>s[i].a>>s[i].b>>s[i].c;
    ll x=-(s[i].b)/(2*s[i].a);
    if(x<0){
      q.push(node{i,1,s[i].a+s[i].b+s[i].c,1});
      continue;
    }
    if(s[i].b%(2*s[i].a)==0){
      q.push(node{i,0,s[i].a*x*x+s[i].b*x+s[i].c,x});
      if(x-1>0)q.push(node{i,-1,s[i].a*(x-1)*(x-1)+s[i].b*(x-1)+s[i].c,x-1});
      q.push(node{i,1,s[i].a*(x+1)*(x+1)+s[i].b*(x+1)+s[i].c,x+1});
    }
    else {
      q.push(node{i,-1,s[i].a*x*x+s[i].b*x+s[i].c,x});
      q.push(node{i,1,s[i].a*(x+1)*(x+1)+s[i].b*(x+1)+s[i].c,x+1});
    }
  }
  ll tmp=1;
  while(tmp<=m){
    ll id=q.top().id,op=q.top().op,num=q.top().num,x=q.top().x;
    q.pop();
    if(x<=0)continue;
    cout<<num<<' ';
    tmp++;
    if(op==1||op==-1){
      q.push(node{id,op,s[id].a*(x+op)*(x+op)+s[id].b*(x+op)+s[id].c,x+op});
    }
  }
  return 0;
}