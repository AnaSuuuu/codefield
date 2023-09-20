#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+5;
priority_queue<ll,vector<ll>,greater<ll> >q;
ll main(){
  freopen("1090.in","r",stdin);
  freopen("1090.out","w",stdout);
  ll n;
  cin>>n;
  for(ll i=1;i<=n;i++){
    ll x;
    cin>>x;
    q.push(x);
  }
  ll ans=0;
  while(q.size()>1){
    ll a=q.top();
    q.pop();
    ll b=q.top();
    q.pop();
    //cout<<a<<' '<<b<<endl;
    ans+=a+b;
    q.push(a+b);
  }
  cout<<ans<<endl;
  return 0;
}