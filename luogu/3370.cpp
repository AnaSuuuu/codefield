#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull base=131;
char s[1505];
ull a[10005];
ull Hash(char c[]){
  ll len=strlen(c);
  ull x=0;
  for(ll i=0;i<len;i++)
    x=x*base+c[i]-'0';
  return x;
}
ll main(){
  freopen("3370.in","r",stdin);
  freopen("3370.out","w",stdout);
  ll n;
  cin>>n;
  for(ll i=1;i<=n;i++){
    scanf("%s",s);
    a[i]=Hash(s);
  }
  sort(a+1,a+1+n);
  ll ans=1;
  for(ll i=1;i<n;i++)
    if(a[i]!=a[i+1])ans++;
  cout<<ans<<endl;
}