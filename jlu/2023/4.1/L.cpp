#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N];
int main(){
  int len;
  scanf("%d",&len);
  scanf("%s",s+1);
  for(int i=2,j;i<=len;i++){
    for(j=i;j<=len;j++){
      if(s[j]!=s[j-i+1])break;
    }
    if(j>len){
      puts("Wrong Answer");
      return 0;
    }
  }
  puts("Correct");
  return 0;
}