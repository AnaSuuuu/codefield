#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 2e5 + 5;
const int mod = 998244353;
const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();
vector<int> e[N];
ull Hash[N];
long long ra;
map<ull, bool> M;
map<ull, int> las;
ull h(ull x) {
    return (x * x % mod * x % mod * 1237123 % mod + 19260817) % mod;
}
ull f(ull x) {
    ull cur = h(x & ((1 << 31) - 1)) + h(x >> 31) % mod;
    return cur % mod;
}
void dfs(int u, int fa){
  Hash[u] = 1; //+ ra;
  //long long mul = 1;
  for(int i: e[u]){
    if(i == fa)continue;
    dfs(i, u);
    Hash[u] += f(Hash[i]);
    /*Hash[u] %= mod;
    mul *= Hash[i];
    mul %= mod;*/
  }
  //Hash[u] += mul;
  //Hash[u] %= mod;
} 
bool judge(int u,int fa){
  //cout << u << endl;
  M.clear();
  las.clear();
  set<int> s;
  int tot = 0;
  for(int i: e[u]){
    if(i == fa) continue;
    if(M[Hash[i]]) tot--, s.erase(las[Hash[i]]);
    else {
      tot++; 
      s.emplace(i); 
      las[Hash[i]] = i;
      //cout<<las[Hash[i]]<<' '<<i<<endl;
      //puts("BBB");
    }
    M[Hash[i]] ^= 1;
    //if(u == 1)cout << i << ' ' << Hash[i] << ' ' << las[Hash[i]] << ' ' << M[Hash[i]] << ' ' << s.size() << endl;
    
  }
  //cout << endl;
  //cout << *s.begin() << "AAA" << endl;
  if(tot == 0) return 1;
  if(tot >= 2) return 0;
  return judge(*s.begin(), u);
}
int main(){
  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);
  int T;
  cin >> T;
  while(T--){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) e[i].clear();
    for( int i = 1; i < n; i++){
      int u, v;
      cin >> u >> v;
      e[u].emplace_back(v);
      e[v].emplace_back(u);
    }
    dfs(1, 0);
    //for(int i = 1; i <= n; i++)cout << Hash[i] << ' ';
    //cout << endl;
    //for(int i = 1; i <= n; i++) cout << Hash[i] << endl;
    if(judge(1, 0)) puts("YES");
    else puts("NO");/**/
  }

  /*cout<<endl<<endl;
  set<int >q;
  q.emplace(1);
  cout<<q.size()<<endl;
  q.erase(1);
  cout<<q.size()<<endl;*/
  return 0;
}