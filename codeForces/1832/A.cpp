#include<bits/stdc++.h>
using namespace std;
const int N = 55;
char s[N];
int main(){
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int t;
  cin >> t;
  while(t--) {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    int ok = 0;
    for(int i = 2; i <= len / 2; i++) {
      if(s[i] != s[i - 1]){
        ok = 1;
        puts("YES");
        break;
      }
    }
    if(!ok) puts("NO");
  }
  return 0;
}