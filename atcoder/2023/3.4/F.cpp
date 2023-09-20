#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("F.in","r",stdin);
  freopen("F.out","w",stdout);
  double a,b;
  cin>>a>>b;
  if(a<b)swap(a,b);
  if(a/2*sqrt(3)>b)printf("%.10lf",b/sqrt(3)*2);
  else printf("%.10lf",2*sqrt(a*a+b*b-sqrt(3)*a*b));
  return 0;
}