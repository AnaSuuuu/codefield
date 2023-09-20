#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
ll Map[N];
struct Node{
  ll id;
  struct Node *head;
  struct Node *next;
}s[N];
ll main(){
  freopen("1160.in","r",stdin);
  freopen("1160.out","w",stdout);
  ll n;
  cin>>n;
  for(ll i=0;i<=n;i++){
  	s[i].id=i;
  	s[i].head=NULL;
  	s[i].next=NULL;
  }
  struct Node *Head=&s[1];
  struct Node *Next=&s[1];
  for(ll i=2;i<=n;i++){
    ll k,p;
    cin>>k>>p;
    switch(p){
      case 0:{
      	struct Node *x=&s[k];
      	struct Node *y=&s[i];
        if((Head->id)==k){
        	x->head=y;
        	y->next=x;
        	Head=y;
		}
		else {
			y->next=x;
			y->head=x->head;
			x->head=y;
			y->head->next=y;
		}
        break;
      }
      case 1:{
        struct Node *x=&s[k];
      	struct Node *y=&s[i];
        if((Next->id)==k){
        	x->next=y;
        	y->head=x;
        	Next=y;
		}
		else {
			y->head=x;
			y->next=x->next;
			x->next=y;
			y->next->head=y;
		}
        break;
      }
    }
  }
  ll m;
  cin>>m;
  while(m--){
  	ll p;
  	cin>>p;
  	if(Map[p])continue;
  	Map[p]=1;
  	if(Head->id==p)Head=Head->next;
  		else {
  			if(Next->id==p){
  				s[p].head->next=s[p].next;	
  				Next=Next->head;
			}
			else {
				s[p].head->next=s[p].next;	
				s[p].next->head=s[p].head;
			}
		}
  }
  while(Head!=NULL){
  	cout<<Head->id<<' ';
  	Head=Head->next;
  }
  return 0;
}
