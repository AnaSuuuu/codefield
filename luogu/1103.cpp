#include<bits/stdc++.h>
using namespace std;
const ll N=105;
struct Node{
  ll h,w;
}a[N];
bool cmp(Node x,Node y){
  return x.h<y.h;
}
ll f[N][N];//f[i][j]前i本选第i本情况下共选了j本的最小不整齐度f[i][j]=min{f[k][j-1]+abs(w[i]-w[k])}
ll main(){
  freopen("1103.in","r",stdin);
  freopen("1103.out","w",stdout);
  ll n,k;
  cin>>n>>k;
  for(ll i=1;i<=n;i++)
    cin>>a[i].h>>a[i].w;
  sort(a+1,a+1+n,cmp);
  memset(f,0x3f,sizeof(f));
  for(ll i=1;i<=n;i++){
    f[i][1]=0;
    for(ll j=2;j<=i;j++)
      for(ll k0=1;k0<i;k0++)
        f[i][j]=min(f[i][j],f[k0][j-1]+abs(a[i].w-a[k0].w));
  }
  ll ans=0x3f3f3f3f;
  for(ll i=1;i<=n;i++)ans=min(ans,f[i][n-k]);
  cout<<ans<<endl;
  return 0;
}