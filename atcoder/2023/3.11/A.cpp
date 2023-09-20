#include<bits/stdc++.h>
using namespace std;
char a[105];
int main(){
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  scanf("%s",a+1);
  for(int i=1;i<=strlen(a+1);i+=2)printf("%c%c",a[i+1],a[i]);
  return 0;
}