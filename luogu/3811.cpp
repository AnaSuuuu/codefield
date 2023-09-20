#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e6+5;
int inv[N];

int main(){
  freopen("3811.in","r",stdin);
  freopen("3811.out","w",stdout);
  int n,p;
  scanf("%d%d",&n,&p);
  inv[1]=1;
  for(int i=2;i<=n;i++){
    inv[i]=(ll)(p-p/i)*inv[p%i]%p;
  }
  for(int i=1;i<=n;i++)cout<<inv[i]<<endl;
  return 0;
}