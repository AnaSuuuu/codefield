#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int s[N];
int main()
{
  //freopen("C.in","r",stdin);
  //freopen("C.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--){
    int n,maxn1=0,maxn2=0,id1,id2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++){
      if(s[i]>=maxn2){
        maxn2=s[i];
        id2=i;
      }
      if(maxn2>=maxn1){
        maxn2^=maxn1^=maxn2^=maxn1;
        id2^=id1^=id2^=id1;
      }  
    }
    for(int i=1;i<=n;i++){
        if(i!=id1)printf("%d ",s[i]-maxn1);
        else printf("%d ",s[i]-maxn2);
      }
    puts("");
  }/**/
  return 0;
} 
