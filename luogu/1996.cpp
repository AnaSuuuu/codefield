#include<bits/stdc++.h>
using namespace std;
const ll N=105;
struct Node{
  ll id;
  struct Node *next;
  struct Node *head;
}s[N];
ll main(){
  freopen("1996.in","r",stdin);
  freopen("1996.out","w",stdout);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=n;i++){
    s[i].id=i;
    s[i].next=&s[i+1];
    s[i].head=&s[i-1];
  }
  s[1].head=&s[n];
  s[n].next=&s[1];
  struct Node *tmp=&s[0];
  s[0].next=&s[1];
  for(ll i=1;i<=n;i++){  
    for(ll j=1;j<=m;j++)tmp=tmp->next;
    prllf("%d ",tmp->id);
    tmp->head->next=tmp->next;
    tmp->next->head=tmp->head;
  }
  return 0;
}