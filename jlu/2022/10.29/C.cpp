#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
void in(int &x){
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
int cal(int a,int b,int c){
  return max(max(abs(a-b)+abs(c-b),abs(a-c)+abs(b-c)),abs(b-a)+abs(b-c));
}
int main(){
  //freopen("C.in","r",stdin);
  //freopen("C.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--){
    int n,id,ans=0;
    in(n);
    for(int i=1;i<=n;i++)in(a[i]);
    sort(a+1,a+1+n);
    for(int i=2;i<n;i++){
      if(max(a[i]-a[i-1],a[i+1]-a[i])+max(a[i]-a[1],a[n]-a[i])>ans)id=i;
      ans=max(ans,max(a[i]-a[i-1],a[i+1]-a[i])+max(a[i]-a[1],a[n]-a[i]));
    }
    ans=max(ans,a[n]-a[n-1]+a[n]-a[1]);
    ans=max(ans,a[2]-a[1]+a[n]-a[1]);
    if(n==3)ans=cal(a[1],a[2],a[3]);
    //cout<<a[id]<<endl;
    printf("%d\n",ans);
  }
  return 0;
}