#include<bits/stdc++.h>
using namespace std;
const ll N=105;
char s[N];
ll len,md[N],kdl;
char _s[N][N];
ll cal(ll sta){
  ll kdl=0;
  for(ll i=sta;i;i++){
    if(s[i]=='(')kdl++;
    if(s[i]==')')kdl--;
    if(kdl==0)return i; 
  }
}
void work(ll l,ll r){
  if(l>r)return ;
  switch(s[l]){
    case '+':{
      for(ll i=l+1;i<=r;){
        if(s[i]=='+'||s[i]=='-'){
          work(l+1,i-1);
          _s[1][++len]='+';
          work(i,r);
          return ;
        }
        else {
          if(s[i]=='(')i=cal(i)+1;
          else i++;
        }
      }
      work(l+1,r);
      _s[1][++len]='+';
      return ;
    }
    case '-':{
      for(ll i=l+1;i<=r;){
        if(s[i]=='+'||s[i]=='-'){
          work(l+1,i-1);
          _s[1][++len]='-';
          work(i,r);
          return ;
        }
        else {
          if(s[i]=='(')i=cal(i)+1;
          else i++;
        }
      }
      work(l+1,r);
      _s[1][++len]='-';
      return ;
    }
    case '/':{
      for(ll i=l+1;i<=r;){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
          work(l+1,i-1);
          _s[1][++len]='/';
          work(i,r);
          return ;
        }
        else {
          if(s[i]=='(')i=cal(i)+1;
          else i++;
        }
      }
      work(l+1,r);
      _s[1][++len]='/';
      return ;
    }
    case '*':{
      for(ll i=l+1;i<=r;){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
          work(l+1,i-1);
          _s[1][++len]='*';
          work(i,r);
          return ;
        }
        else {
          if(s[i]=='(')i=cal(i)+1;
          else i++;
        }
      }
      work(l+1,r);
      _s[1][++len]='*';
      return ;
    }
    case '^':{
      for(ll i=l+1;i<=r;){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
          work(l+1,i-1);
          _s[1][++len]='^';
          work(i,r);
          return ;
        }
        else {
          if(s[i]=='(')i=cal(i)+1;
          else i++;
        }
      }
      work(l+1,r);
      _s[1][++len]='^';
      return ;
    }
    case '(':{
      work(l+1,cal(l)-1);
      work(cal(l)+1,r);
      return ;
    }
  }
  _s[1][++len]=s[l];
  work(l+1,r);
  return ;
}
ll main(){
  freopen("1175.in","r",stdin);
  freopen("1175.out","w",stdout);
  scanf("%s",s+1);
  work(1,strlen(s+1));
  for(ll i=1;i<=len;i++)cout<<_s[1][i]<<' ';
  puts("");
  for(ll i=1;i<=len;i++){
    if(_s[1][i]>='0'&&_s[1][i]<='9'){
      md[++kdl]=_s[1][i]-'0';
      continue;
    }
    switch(_s[1][i]){
      case '+':{
        md[kdl-1]=(md[kdl-1])+(md[kdl]);
        kdl--;
        for(ll j=1;j<=kdl;j++)cout<<md[j]<<' ';
        for(ll j=i+1;j<=len;j++)cout<<_s[1][j]<<' ';
        cout<<endl;
        break;
      }
      case '-':{
        md[kdl-1]=(md[kdl-1])-(md[kdl]);
        kdl--;
        for(ll j=1;j<=kdl;j++)cout<<md[j]<<' ';
        for(ll j=i+1;j<=len;j++)cout<<_s[1][j]<<' ';
        cout<<endl;
        break;
      }
      case '*':{
        md[kdl-1]=(md[kdl-1])*(md[kdl]);
        kdl--;
        for(ll j=1;j<=kdl;j++)cout<<md[j]<<' ';
        for(ll j=i+1;j<=len;j++)cout<<_s[1][j]<<' ';
        cout<<endl;
        break;
      }
      case '/':{
        md[kdl-1]=(md[kdl-1])/(md[kdl]);
        kdl--;
        for(ll j=1;j<=kdl;j++)cout<<md[j]<<' ';
        for(ll j=i+1;j<=len;j++)cout<<_s[1][j]<<' ';
        cout<<endl;
        break;
      }
      case '^':{
        md[kdl-1]=pow((md[kdl-1]),(md[kdl]));
        kdl--;
        for(ll j=1;j<=kdl;j++)cout<<md[j]<<' ';
        for(ll j=i+1;j<=len;j++)cout<<_s[1][j]<<' ';
        cout<<endl;
        break;
      }
    }
  }
  return 0;
}