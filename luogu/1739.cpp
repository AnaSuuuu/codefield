#include<bits/stdc++.h>
using namespace std;
char s[305];
ll main(){
  freopen("1739.in","r",stdin);
  freopen("1739.out","w",stdout);
  scanf("%s",s+1);
  ll tmp=0;
  for(ll i=1;i<=strlen(s+1);i++){
    if(s[i]=='(')tmp++;
    if(s[i]==')')tmp--;
    if(tmp<0){
      puts("NO");
      return 0;
    }
  }
  if(tmp!=0)puts("NO");
  else puts("YES");
  return 0;
}