#include <iostream>
#include <vector>
using namespace std;
vector<int> processString(string s) {
  vector<int> res;
  int x = 0;
  bool read = false;
  for (auto c : s) {
    if (c < '0' || c > '9') {
      if (read) {
        res.push_back(x);
        read = false;
        x = 0;
      }
    }
    if (c >= '0' && c <= '9') {
      x = x * 10 + c - '0';
      read = true;
    }
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    getline(cin, s);
    getline(cin, s);
    vector<int> v = processString(s);
    int x, y;
    cin >> x >> y;
    cout << '[';
    int cur = 0;
    for (int i = 1; i <= x; i++) {
      cout << '[';
      for (int j = 1; j <= y; j++) {
        cout << v[cur];
        cur++;
        if (j != y) cout << ", ";
      }
      cout << ']';
      if (i != x) cout << ", ";
    }
    cout << ']';
    cout << endl;
  }
  return 0;
}