#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
struct Node{
  ll id,num;
  bool operator < (const Node &x) const {
    return x.num<num;
  }
};
ll a[N];
priority_queue<Node> q;
ll main(){
  freopen("2251.in","r",stdin);
  freopen("2251.out","w",stdout);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=n;i++)cin>>a[i];
  for(ll i=1;i<=m;i++){
    q.push(Node{i,a[i]});
  }
  for(ll i=m+1;i<=n+1;i++){
    ll id=q.top().id,num=q.top().num;
    while(id<i-m){
      q.pop();
      id=q.top().id,num=q.top().num;
    }
    cout<<num<<endl;
    q.push(Node{i,a[i]});
  }
  return 0;
}