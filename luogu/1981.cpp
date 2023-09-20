#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
char s;
ll md[N],num[N],num2[N];
ll main(){
  freopen("1981.in","r",stdin);
  freopen("1981.out","w",stdout);
  //cin>>s;
  ll tmp=0,kdl=0,kdl2=0;
  while(cin>>s){
    if(s>='0'&&s<='9')tmp=tmp*10+s-'0';
    else {
      if(s=='+')md[++kdl]=1;
      else md[++kdl]=2;
      //cout<<tmp<<endl;
      num[kdl]=tmp,tmp=0;
    }
    tmp%=10000;
    //if(i==strlen(s+1)) puts(""); 
    //cin>>s;
  }
  //cout<<tmp<<endl;
  num[++kdl]=tmp;
  num2[++kdl2]=num[1];
  for(ll i=1;i<kdl;i++){
    if(md[i]==2){
      num2[kdl2]*=num[i+1];
      num2[kdl2]%=10000;
    }
    else num2[++kdl2]=num[i+1];
  }
  //cout<<num[kdl]<<endl;
  ll ans=0;
  for(ll i=1;i<=kdl2;i++)ans+=num2[i],ans%=10000;
  //cout<<num2[1]<<' '<<num2[kdl2-1]<<endl;
  prllf("%d\n",ans);
  return 0;
}
