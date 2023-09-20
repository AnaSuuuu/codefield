#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll a[N],sum[N],c,d;
ll n,S;
bool judge(ll lim){
  ll num;
  if(lim==0)return 1;
  ll xhj_num = sum[min(n,lim + 1)], xhj_len = lim + 1;
  num=sum[min(d%(lim+1),n)]+d/xhj_len*xhj_num;
 // cout<<num<<endl;
  return (num>=c);
}
int main(){
  //freopen("F.in","r",stdin);
  //freopen("F.out","w",stdout);
  int t;
  cin>>t;
  while(t--){
    memset(sum,0,sizeof(sum));
    ll ans;
    S=0;
    cin>>n>>c>>d;
    for(int i=1;i<=n;i++)cin>>a[i],S+=a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[n-i+1];
    if((S>=c&&n<=d)||(n>d&&sum[d]>=c)){
      puts("Infinity");
      continue;
    }
    if(d*a[n]<c){
      puts("Impossible");
      continue;
    }
   /*for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    cout<<endl;
    for(int i=1;i<=n;i++)cout<<sum[i]<<' ';
    cout<<endl; */
    //cout << judge(6) << endl;
    int l=0,r=d;
    while(l<=r){
      int mid=(l+r)>>1;
      if(judge(mid)){
        ans=mid;l=mid+1;
      }
      else r=mid-1;
    }
    cout<<ans<<endl;;
  }
  return 0;
}