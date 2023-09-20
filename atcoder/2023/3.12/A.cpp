#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  if(a==0||b==0)return max(a,b);
  if(a%b==0)return b;
  return gcd(b,a%b);
}
int lcm(int a,int b){
  return a*b/gcd(a,b);
}
int main(){
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--)  {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)a^=b^=a^=b;
    if(a>c)a^=c^=a^=c;
    if(b>c)b^=c^=b^=c;
    if((b-a)%2||(c-b)%2){
      puts("-1");
      continue;
    }
    if((c-b)/2==(b-a)/2){
      printf("%d\n",(c-b)/2);
      continue;
    }
    if((b-a)/2>(c-b)/2){
      int ans=(c-b)/2;
      a+=(c-b);
      b=c;
      if((b-a)%6){
        puts("-1");
      }
      else {
        ans+=(b-a)/6*2;
        printf("%d\n",ans);
      }
      continue;
    }
    if((c-b)/2>(b-a)/2){
      int ans=(b-a)/2;
      b+=(b-a);
      if((c-b)%6){
        puts("-1");
      }
      else {
        printf("%d\n",ans+(c-b)/6*2);
      }
      continue;
    }
  } 
  return 0;
}