#include<bits/stdc++.h>
using namespace std;
const int N=105;
int cnt[N];
int main(){
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  int n,q;
  cin>>n>>q;
  for(int i=1;i<=q;i++){
    int x,c;
    cin>>c>>x;
    switch(c){
      case 1:{
        cnt[x]++;
        break;
      }
      case 2:{
        cnt[x]+=2;
        break;
      }
      case 3:{
        if(cnt[x]>=2)puts("Yes");
        else puts("No");
        break;
      }
    }
  }
  return 0;
}