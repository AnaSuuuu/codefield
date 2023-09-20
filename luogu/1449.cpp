#include<bits/stdc++.h>
using namespace std;
const ll N=105;
char s[N];
stack<ll> q;
ll main(){
  freopen("1449.in","r",stdin);
  freopen("1449.out","w",stdout);
  scanf("%s",s+1);
  ll tmp=0;
  for(ll i=1;i<strlen(s+1);i++){
    if(s[i]>='0'&&s[i]<='9')tmp=tmp*10+s[i]-'0';
    else {
      if(s[i]=='.'){
        q.push(tmp);
        tmp=0;
      }
      else {
        ll a=q.top();
        q.pop();
        ll b=q.top();
        q.pop();
        switch(s[i]){
          case '+':{
            q.push(a+b);
            break;
          }
          case '-':{
            q.push(b-a);
            break;
          }
          case '*':{
            q.push(a*b);
            break;
          }
          case '/':{
            q.push(b/a);
            break;
          }
        }
      }
    }
  }
  cout<<q.top();
  return 0;
}