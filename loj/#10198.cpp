#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("#10198.in","r",stdin);
  freopen("#10198.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      printf("%d\n",n/i);
      return 0;
    }
  }
  return 0;
}