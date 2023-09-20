#include <bits/stdc++.h>
using namespace std;
int main(){
  //freopen("A.in", "r", stdin);
  //freopen("A.out", "w", stdout);
  int t;
  scanf("%d", &t);
  while(t--){
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    if(a<b)a^=b^=a^=b;
    if(a<c)a^=c^=a^=c;
    if(c>b)b^=c^=b^=c;
    printf("%d\n",b);
  }
  return 0;
}