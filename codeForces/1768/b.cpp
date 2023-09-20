#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int p[N];
int main(){
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>p[i];
    int tot=1;
    for(int i=1;i<=n;i++)
      if(p[i]==tot)tot++;
    cout<<(k+n-tot)/k<<endl;
  }
  return 0;
}