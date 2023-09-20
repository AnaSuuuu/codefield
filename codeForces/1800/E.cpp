#include<bits/stdc++.h>
using namespace std;
string s, t;
int main(){
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  int T;
  scanf("%d", &T);
  while(T--){
    int n, k, ok = 1;
    vector<int> cnt(26,0);
    scanf("%d%d", &n, &k);
    cin >> s >> t;
    for(int i = 0; i < n; i++){
      if(i >= k || i + k < n){
        cnt[s[i] - 'a']++;
        cnt[t[i] - 'a']--;
      }
      else ok &= (s[i] == t[i]);
    }
    cout << ((ok && (count(cnt.begin(), cnt.end(), 0) == 26)) ? "YES" : "NO") << endl;
  }
  return 0;
}