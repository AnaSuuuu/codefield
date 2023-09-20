#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int num[N];
int main(){
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int t;
  cin >> t;
  while(t--){
    int n;
    memset(num, 0, sizeof(num));
    cin >> n;
    for(int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      num[x]++;
    }
    int ok = 0; 
    for(int i = 1; i <= n; i++) num[i] += num[i - 1];
    for(int i = n; i >= 0; i--){
      if(n - num[i] == i) {
        cout << i << endl;
        ok = 1;
        break;
      } 
    }
    if(ok) continue;
    else puts("-1");
  }
  return 0;
}