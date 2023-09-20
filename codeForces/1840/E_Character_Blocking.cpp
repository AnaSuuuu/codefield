#include<bits/stdc++.h>
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--) {
    queue<pair<int, int>> q;
    string s[3];
    cin >> s[1] >> s[2];
    int t, Q, n;
    n = s[1].size();
    cin >> t >> Q;
    int diff = 0;
    for(int i = 0; i < n; i++) {
      diff += (s[1][i] != s[2][i]);
    }
    //cout << diff << endl;
    for(int i = 1; i <= Q; i++) {
      int op;
      cin >> op;
      switch(op) {
        case 1: {
          int pos;
          cin >> pos;
          diff -= (s[1][pos - 1] != s[2][pos - 1]);
          q.push(make_pair(i, pos));
          break;
        }
        case 2: {
          int k1, k2, pos1, pos2;
          cin >> k1 >> pos1 >> k2 >> pos2;
          diff -= (s[3 - k1][pos1 - 1] != s[k1][pos1 - 1]);
          diff -= (s[3 - k2][pos2 - 1] != s[k2][pos2 - 1]);
          swap(s[k1][pos1 - 1], s[k2][pos2 - 1]);
          diff += (s[3 - k1][pos1 - 1] != s[k1][pos1 - 1]);
          diff += (s[3 - k2][pos2 - 1] != s[k2][pos2 - 1]);
          break;
        }
        case 3: {
          //if(q.size()) cout << q.front().first << ' ' << t << ' ' << i << endl;
          while(q.size() && q.front().first + t <= i) {
            diff += (s[1][q.front().second - 1] != s[2][q.front().second - 1]);
            q.pop(); 
          }
          cout << ((!diff) ? "YES" : "NO") << endl;
          break;
        }
      }
    }
  } 
  return 0;
}