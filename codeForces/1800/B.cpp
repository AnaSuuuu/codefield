#include<bits/stdc++.h>
using namespace std;
const int N=55;
const int M=2e5+5;
int a[N],b[N];
char s[M];
int main(){
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--){
    int n,k,ans=0;
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++){
      char c=s[i];
      int tmp=0;
      if(c>='A'&&c<='Z')tmp=c-'A'+1,a[tmp]++;
      else tmp=c-'a'+1,b[tmp]++;
    }
    for(int i=1;i<=26;i++){
      if(a[i]<b[i])a[i]^=b[i]^=a[i]^=b[i];
      if((a[i]-b[i])/2<k){
        ans+=b[i]+(a[i]-b[i])/2;
        k-=(a[i]-b[i])/2;
      }
      else {
        ans+=b[i]+k;
        k=0;
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}