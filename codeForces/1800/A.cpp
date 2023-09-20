#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N],Map[N];
char s[N];
int main(){
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  int t;
  a['M'-'A']=a['m'-'A']=1;
  a['e'-'A']=a['E'-'A']=2;
  a['o'-'A']=a['O'-'A']=3;
  a['w'-'A']=a['W'-'A']=4;
  scanf("%d",&t);
  while(t--){
    Map[1]=Map[2]=Map[3]=Map[4]=0;
    int n,ok=1;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<n;i++){
      Map[a[s[i]-'A']]=1;
      if(a[s[i]-'A']>a[s[i+1]-'A']){
        puts("NO");
        ok=0;
        break;
      }
    }
    Map[a[s[n]-'A']]=1;
    if(ok==0)continue;
    //puts("AAA");
    //cout<<Map[1]<<' '<<Map[2]<<' '<<Map[3]<<' '<<Map[4]<<endl;
    if((Map[1]==1)&&(Map[2]==1)&&(Map[3]==1)&&(Map[4]==1)&&(a[s[1]-'A']==1)&&ok)puts("YES");
    else puts("NO");
  }
}