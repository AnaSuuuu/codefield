#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string s[N];
map<string,int>name,rep;
int main(){
  freopen("2580.in","r",stdin);
  freopen("2580.out","w",stdout);
  int n,m;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    cin>>s[i];
    name[s[i]]=1;
  }
  scanf("%d",&m);
  string x;
  for(int i=1;i<=m;i++){
    cin>>x;
    if(name[x]==0)puts("WRONG");
    else {
      if(rep[x]==0)puts("OK");
      else puts("REPEAT");
      rep[x]++;
    }
  }
  return 0;
}