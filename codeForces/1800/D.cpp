#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];
int main(){
  freopen("D.in","r",stdin);
  freopen("D.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--){
    int n,ans=0;
    scanf("%d",&n);
    ans=n-1;
    scanf("%s",s+1);
    for(int i=1;i<=n-2;i++)
      if(s[i]==s[i+2])ans--;
    printf("%d\n",ans);
  }
  return 0;
}