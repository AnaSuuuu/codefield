#include<bits/stdc++.h>
using namespace std;
const ll N=55;
ll a[N];
ll main(){
  freopen("1018.in","r",stdin);
  freopen("1018.out","w",stdout);
  ll n,k;
  scanf("%d%d",&n,&k);
  for(ll i=1;i<=n;i++)
  dfs();
  return 0;
}