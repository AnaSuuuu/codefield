#include<bits/stdc++.h>
using namespace std;
int main(){
  //freopen("A.in","r",stdin);
  //freopen("A.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    if(n&1)puts("3");
    else puts("7");
  }
  return 0;
}