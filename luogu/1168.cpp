/*#include<bits/stdc++.h>
using namespace std;
priority_queue<ll,vector<ll> >q1;//大根堆
priority_queue<ll,vector<ll>,greater<ll> >q2;//小根堆
ll main(){
  freopen("1168.in","r",stdin);
  freopen("1168.out","w",stdout);
  ll n;
  cin>>n;
  ll x;
  cin>>x;
  q1.push(x);
  cout<<x<<endl;
  for(ll i=2;i<=n;i++){
    cin>>x;
    if(q1.top()>x)q1.push(x);
    else q2.push(x);
    while(q1.size()+1<q2.size()){
      q1.push(q2.top());
      q2.pop();
    }
    while(q1.size()+1>q2.size()){
      q2.push(q1.top());
      q1.pop();
    }
    if(i%2)cout<<q2.top()<<endl;
  }
  return 0;
} ------------------------法一*/
#include<bits/stdc++.h>
using namespace std;
vector<ll> q;
ll main(){
  freopen("1168.in","r",stdin);
  freopen("1168.out","w",stdout);
  ll n;
  cin>>n;
  for(ll i=1;i<=n;i++){
    ll x;
    cin>>x;
    q.insert(upper_bound(q.begin(),q.end(),x),x);
    if(i%2)cout<<q[(i-1)/2]<<endl;
  }
  return 0;
}//-----------------法二