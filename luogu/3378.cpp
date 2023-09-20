#include<bits/stdc++.h>
using namespace std;
const ll N=1e6+6;
ll tr[N];
ll main(){
  freopen("3378.in","r",stdin);
  freopen("3378.out","w",stdout);
  ll n,len=0;
  cin>>n;
  //memset(tr,0x3f,sizeof(tr));
  while(n--){
    ll op;
    cin>>op;
    switch(op){
      case 1:{
        ll x;
        cin>>x;
        tr[++len]=x;
        ll kdl=len;
        while(kdl){
          if(tr[kdl>>1]>tr[kdl])tr[kdl>>1]^=tr[kdl]^=tr[kdl>>1]^=tr[kdl];
          else break;
          kdl>>=1;
        }
        //cout<<tr[1]<<endl;
        break;
      }
      case 2:{
        cout<<tr[1]<<endl;
        break;
      }
      case 3:{
        ll kdl=1;
        tr[len]^=tr[1]^=tr[len]^=tr[1];
        tr[len]=0;
        len--;
        while(kdl<len){
          ll ls=(kdl<<1),rs=(kdl<<1|1);
          if(ls>len){
            break;
          }
          if(rs>len){
            if(tr[ls]<tr[kdl])tr[kdl]^=tr[ls]^=tr[kdl]^=tr[ls];
            break;
          }
          if(tr[ls]<tr[rs]){
            if(tr[ls]<tr[kdl])tr[kdl]^=tr[ls]^=tr[kdl]^=tr[ls],kdl=ls;
            else break;
          }
          else {
            if(tr[rs]<tr[kdl])tr[kdl]^=tr[rs]^=tr[kdl]^=tr[rs],kdl=rs;
            else break;
          }
        }
        break;
      }
    }
  }
  return 0;
}