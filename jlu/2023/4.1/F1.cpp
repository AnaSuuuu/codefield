#include<bits/stdc++.h>
using namespace std;
int n,m;
bool judge(int lim){
  for(int i=0;i<=lim;i++)
    if((m+i)%(n-(lim-i))==0)return true;
  return false;
}
int main(){
  freopen("F.in","r",stdin);
  freopen("F1.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&n,&m);
    /*int l=1,r=n-1,ans;
    if(m%n==0){
      puts("0");
      continue;
    }
    if(n>m){
      printf("%d\n",n-m);
      continue;
    }
    while(r>=l){
      int mid=l+r>>1;
      if(judge(mid)){
        ans=mid;
        r=mid-1;
      }
      else l=mid+1;
    }
    printf("%d\n",ans);*/
    int ans=0x3f3f3f3f;
    for(int i=0;i<=min(ans,n);i++){
      ans=min(ans,((n-i)-m%(n-i)+(n-i))%(n-i)+i);
      //cout<<ans<<endl;
    }
    printf("%d\n",ans);
  }
  return 0;
}