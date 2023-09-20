#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
double cal(double x){
  return a*x*x*x+b*x*x+c*x+d;
}
double cal0(double l,double r){
  while(r-l>1e-3){
    double mid=(l+r)/2;
    if(cal(mid)==0)return mid;
    if(cal(mid)*cal(l)>0)l=mid;
    else r=mid;
  }
  return r;
}
ll main(){
  freopen("1024.in","r",stdin);
  freopen("1024.out","w",stdout);
  scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
  for(ll i=-100;i<100;i++){
    //cout<<cal(i)<<' '<<cal(i+1)<<endl;
    if(cal(i)==0){
      double kdl=i;
      prllf("%.2lf ",kdl);
    }
    else if(cal(i)*cal(i+1)<0)
          prllf("%.2lf ",cal0(i,i+1));
  }
  if(cal(100)==0)puts("100.00");
}