#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int main(){
  //freopen("D.in","r",stdin);
  //freopen("D.out","w",stdout);
  int t;
  cin>>t;
  while(t--){
    int n,tmp=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      if(a[i]!=b[tmp])b[++tmp]=a[i];
      else continue;
    }
    if(n==1||tmp==1){
      puts("YES");
      continue;
    }
    b[0]=0x3f3f3f3f;
    b[tmp+1]=0x3f3f3f3f;
    for(int i=1;i<=tmp;i++){
      if(b[i-1]>b[i]&&b[i]<b[i+1])cnt++;
    }
    printf("%s\n",cnt==1?"YES":"NO");
  }
  return 0;
}