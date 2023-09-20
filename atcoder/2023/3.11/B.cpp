#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],ans;
int vis[N];
int main(){
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  int n;
  scanf("%d",&n);
  ans=n;
  for(int i=1;i<=n;i++){
    int x;
    scanf("%d",&x);
    if(vis[i])continue;
    if(vis[x]==0)ans--;
    vis[x]=1;
  }
  cout<<ans<<endl;
  for(int i=1;i<=n;i++)
    if(vis[i]==0)cout<<i<<' ';
  return 0;
}