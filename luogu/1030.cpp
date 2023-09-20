#include<bits/stdc++.h>
using namespace std;
const ll N=10;
char a[N],b[N];
ll len1,len2;
ll f(char c){
  for(ll i=1;i<=len1;i++)
    if(a[i]==c)return i;
}
void dfs(ll l1,ll r1,ll l2,ll r2){
  prllf("%c",b[r2]);
  ll tmp=f(b[r2]);
  if(tmp>l1)dfs(l1,tmp-1,l2,l2+tmp-l1-1);
  if(tmp<r1)dfs(tmp+1,r1,r2-r1+tmp,r2-1);
}
ll main(){
  freopen("1030.in","r",stdin);
  freopen("1030.out","w",stdout);
  scanf("%s",a+1);
  scanf("%s",b+1);
  len1=strlen(a+1);
  len2=strlen(b+1);
  dfs(1,len1,1,len2);
  return 0;
}