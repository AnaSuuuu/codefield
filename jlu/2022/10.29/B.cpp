#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct Node{
  ll a,b;
}s[N];
void in(ll &x){
  x=0;
  int zh=1;
  char c=getchar();
  while(c<'0'||c>'9'){
    if(c=='-')zh=-1;
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<1)+(x<<3)+c-'0';
    c=getchar();
  }
  x*=zh;
}

int main(){
  //freopen("B.in","r",stdin);
  //freopen("B.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--){
    ll n,maxn=0,id,ans=0;
    in(n);
    for(int i=1;i<=n;i++){
      in(s[i].a);in(s[i].b);
      if(s[i].a>maxn||s[i].b>maxn)maxn=max(s[i].a,s[i].b),id=i;
    }
    for(int i=1;i<=n;i++){
      if(id==i)ans+=2*(s[i].a+s[i].b);
      else ans+=min(s[i].a,s[i].b)*2;
    }
    printf("%lld\n",ans);
  }
  return 0;
}