#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],f[N][25];
int n,m;
void pre_st(){
  for(int i=1;i<=n;i++)f[i][0]=a[i];
  for(int i=1;i<=25;i++){
    for(int j=1;j+(1<<(i-1))<=n;j++){
      f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
    }
  }
}
void query(int l,int r){
  int k=log2(r-l+1);
  printf("%d\n",max(f[l][k],f[r-(1<<k)+1][k]));
}
int main(){
  freopen("#10119.in","r",stdin);
  freopen("#10119.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  pre_st();
  for(int i=1;i<=m;i++){
    int l,r;
    scanf("%d%d",&l,&r);
    query(l,r);
  }
  return 0;
}