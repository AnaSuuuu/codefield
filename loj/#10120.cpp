#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],f1[N][25],f2[N][25];
int n,k;
void pre_st(){
  for(int i=1;i<=n;i++)f1[i][0]=f2[i][0]=a[i];
  for(int i=1;i<=25;i++){
    for(int j=1;j+(1<<i)-1<=n;j++){
      f1[j][i]=max(f1[j][i-1],f1[j+(1<<(i-1))][i-1]);
      f2[j][i]=min(f2[j][i-1],f2[j+(1<<(i-1))][i-1]);
    }
  }
}
void query(int l,int r){
  int x=log2(r-l+1);
  printf("%d %d\n",max(f1[l][x],f1[r-(1<<x)+1][x]),min(f2[l][x],f2[r-(1<<x)+1][x]));
}
int main(){
  freopen("#10120.in","r",stdin);
  freopen("#10120.out","w",stdout);
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  pre_st();
  for(int i=1;i<=n-k+1;i++)query(i,i+k-1);
  return 0;
}