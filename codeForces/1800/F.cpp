#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
string s[N];
int a[N], b[N], c[N];
int main(){
  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);
  int n;
  ll ans = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    cin >> s[i];
  }
  for(int i = 1; i <= n; i++){
    for(char c: s[i]){
      a[i] |= (1 << (c - 'a'));
      b[i] ^= (1 << (c - 'a'));
    }
  }
  for(int i = 0; i < 26; i++){
    int tot = 0;
    for(int j = 1; j <= n; j++){
      if(a[j] & (1 << i)) continue;
      else c[++tot] = b[j];
    }
    
    sort(c + 1,c + 1 + tot);
    for(int j = 1; j <= tot; j++){
      ans += upper_bound(c + 1, c + 1 + tot, (((1 << 26) - 1) ^ c[j]) - (1 << i) ) - lower_bound(c + 1, c + 1 + tot, (((1 << 26) - 1) ^ c[j]) - (1 << i));
    }  
  }
  cout << ans / 2 << endl;
  return 0; 
}