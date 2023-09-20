#include<bits/stdc++.h>
using namespace std;
const int N=105;
char a[N];
int main(){
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  scanf("%s",a+1);
  for(int i=1;i<=strlen(a+1);i++)printf("%c",a[i]-32);
  return 0;
}