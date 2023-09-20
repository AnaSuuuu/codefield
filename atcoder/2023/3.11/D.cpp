#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int fa[N],cnt[N],cnt0[N];
int get_fa(int x){
  return (fa[x]==x?x:(fa[x]=get_fa(fa[x])));
}
int main(){
  freopen("D.in","r",stdin);
  freopen("D.out","w",stdout);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)fa[i]=i;
  for(int i=1;i<=m;i++){
    int x,y;
    char a,b;
    scanf("%d %c %d %c",&x,&a,&y,&b);
    int fx=get_fa(x),fy=get_fa(y);
    fa[fx]=fy;
    cnt[fx]++;
  }
  for(int i=1;i<=n;i++)cnt0[i]++;
  int ans1=0;
  for(int i=1;i<=n;i++){
    if(get_fa(i)!=i)cnt[get_fa(i)]+=cnt[i];
    else ans1++;
    if(i!=get_fa(i))cnt0[get_fa(i)]++;
  }
  int ans2=0;
  for(int i=1;i<=n;i++){
    if(i==get_fa(i)){
      if(cnt[i]==cnt0[i])ans2++;
    }
  }
  printf("%d %d\n",ans2,ans1-ans2);
  return 0;
}