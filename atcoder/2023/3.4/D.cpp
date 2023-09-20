#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int fa[N];
int cnt_n[N],cnt_e[N];
inline int get_fa(int x){ 
  return (fa[x]==x?x:fa[x]=get_fa(fa[x]));
}
  int main(){
  freopen("D.in","r",stdin);
  freopen("D.out","w",stdout);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)fa[i]=i,cnt_n[i]=1;
  for(int i=1;i<=m;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    int fu=get_fa(u),fv=get_fa(v);
    if(fv!=fu){
      fa[get_fa(fv)]=fu;
    }
    cnt_e[fv]++;
  }
  for(int i=1;i<=n;i++){
    if(get_fa(i)!=i){
      cnt_n[get_fa(i)]+=cnt_n[i];
      cnt_e[get_fa(i)]+=cnt_e[i];
    }
  }
  //for(int i=1;i<=n;i++)cout<<get_fa(i)<<' ';
  //cout<<endl;
  //for(int i=1;i<=n;i++)cout<<cnt_e[i]<<' ';
  //cout<<endl;
  //for(int i=1;i<=n;i++)cout<<cnt_n[i]<<' ';
  for(int i=1;i<=n;i++){
    if(get_fa(i)==i){
      if(cnt_n[i]!=cnt_e[i]){
        puts("No");
        return 0;
      }
    }
  }
  puts("Yes");
  return 0;
}
