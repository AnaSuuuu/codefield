  #include<bits/stdc++.h>
  using namespace std;
  string s;
  bool check(int l, int r){
    for(int i = l; i < r; i++) if(s[i] != s[r - 1 - (i - l)]) return true;
    return false;
  }
  int main(){
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
      s.clear();
      cin >> s;
      int ok = 1;
      for(int i = 1; i < s.length(); i++) 
        if(check(i, s.length())) {
          ok = 0;
        // cout << i << ' ' << s.length() << endl;
          //for(int j = i; j < s.length(); j++) cout <<s[j];
        // puts("");
          cout << s.length() - i << endl;
          break;
        }
      if(ok) puts("-1");
    }
    return 0;
  }