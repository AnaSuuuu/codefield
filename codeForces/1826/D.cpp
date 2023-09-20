#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int b[N];
map<int, int> M; 
struct Node{
  int id, num;
  bool operator < (const Node &a) const {
    return a.num < num;
  }
}s[N];
set<Node> q1, q2;
int main(){
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int t;
  cin >> t;
  while(t--){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    M.clear();
    q1.clear();
    q2.clear();
    for(int i = 2; i <= n; i++) {
      q2.emplace(Node{i, b[i] - i});
      M[b[i] - i]++;
    }
    
    q1.emplace(Node{1, b[1] - 1});
    int ans = 0;
    for(int i = 2; i < n; i++){
      //if(q2.find(Node{i, b[i] - 1}) != q2.end()) 
      //for(set<Node>::iterator it = q2.begin();it != q2.end(); ++it) cout << (*it).num << ' ';
      //cout << endl;
      //for(set<Node>::iterator it = q1.begin();it != q1.end(); ++it) cout << (*it).num << ' ';
      //cout << endl;
      M[b[i] - i]--;
      if(M[b[i] - i] == 0)q2.erase(Node{i, b[i] - i});
      //cout << b[i] << ' ' << (*q1.begin()).num << ' ' << (*q2.begin()).num << endl;
      ans = max(ans, b[i] + (*q1.begin()).num + 2 + (*q2.begin()).num);
      q1.emplace(Node{i, b[i] + i - 2});
    }
    printf("%d\n", ans);
  }
  return 0;
}