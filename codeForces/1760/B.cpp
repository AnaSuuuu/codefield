#include<bits/stdc++.h>
using namespace std;
const int N=105;
char s[N];
int main(){
  //freopen("B.in","r",stdin);
  //freopen("B.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--){
    int n,maxn=0;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)maxn=max(maxn,s[i]-'a'+1);
    cout<<maxn<<endl;
  }
  return 0;
}