#include<bits/stdc++.h>
using namespace std;
int main(){
  int b1,b2,b3,b4,b5;
  int a1,a2,a3,a4,a5;
  cin>>b1>>b2>>b3>>b4>>b5;
  cin>>a1>>a2>>a3>>a4>>a5;
  if(b1+b2+b3+b4+b5>=a1+a2+a3+a4+a5)puts("Blue");
  else puts("Red");
}