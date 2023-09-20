#include<bits/stdc++.h>
using namespace std;
const ll N=1e6+5;
struct Node{
  ll num,id;
}s[N];
deque<Node> q;
ll main(){
  freopen("1886.in","r",stdin);
  freopen("1886.out","w",stdout);
  ll n,k;
  scanf("%d%d",&n,&k);
  for(ll i=1;i<=n;i++)scanf("%d",&s[i].num);
  for(ll i=1;i<=k;i++){
    while(q.size()){
      ll tmp=q.back().num;
      if(tmp<s[i].num)break;
      q.pop_back();
    }
    q.push_back(Node{s[i].num,i});
  }
  prllf("%d ",q.front().num);
  for(ll i=k+1;i<=n;i++){
    while(q.size()){
      if(q.front().id>i-k)break;
      q.pop_front();
    }
    while(q.size()){
      ll tmp=q.back().num;
      if(tmp<s[i].num)break;
      q.pop_back();
    }
    q.push_back(Node{s[i].num,i});
    prllf("%d ",q.front().num);
  }
  q.clear();
  puts("");
  
  for(ll i=1;i<=k;i++){
    while(q.size()){
      ll tmp=q.back().num;
      if(tmp>s[i].num)break;
      q.pop_back();
    }
    q.push_back(Node{s[i].num,i});
  }
  prllf("%d ",q.front().num);
  for(ll i=k+1;i<=n;i++){
    while(q.size()){
      if(q.front().id>i-k)break;
      q.pop_front();
    }
    while(q.size()){
      ll tmp=q.back().num;
      if(tmp>s[i].num)break;
      q.pop_back();
    }
    q.push_back(Node{s[i].num,i});
    prllf("%d ",q.front().num);
  }
  return 0;
}