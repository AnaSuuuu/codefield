#include<bits/stdc++.h>
using namespace std;
const ll N=1005;
bool Map[N];
ll s[N];
queue<ll> q;
ll main(){
  freopen("1540.in","r",stdin);
  freopen("1540.out","w",stdout);
  ll m,n,len=0,ans=0;
  cin>>m>>n;
  for(ll i=1;i<=n;i++)cin>>s[i];
  for(ll i=1;i<=n;i++){
    if(Map[s[i]])continue;
    if(len<m){
      q.push(s[i]);
      ans++;
      len++;
      Map[s[i]]=1;
    }
    else {
      ll tmp=q.front();
      q.pop();
      ans++;
      Map[s[i]]=1;
      Map[tmp]=0;
      q.push(s[i]);
    }
  }
  cout<<ans<<endl;
}