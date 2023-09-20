#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[15][105];
bool vis[1505];
int dis[1505];
int x[105], y[105];
int main(){
  freopen("2622.in", "r", stdin);
  freopen("2622.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++) {
    	int c;
    	cin >> c;
    	if(c == 1) x[i] += (1 << (j - 1));
    	else if(c == -1) y[i] += (1 << (j - 1));
		}
  }
  queue<int> q;
  q.push(0);
  vis[0] = 1;
  memset(dis, 0x3f, sizeof(dis));
  dis[0] = 0;
  while(q.size()){
  	int tmp = q.front();
		q.pop();
		for(int i = 1; i <= m; i++) {
			int sta = tmp - (tmp & y[i]);
			sta |= x[i];
			if(vis[sta]) continue;
			dis[sta] = dis[tmp] + 1;
			vis[sta] = 1;
			q.push(sta);
		}
	}
	if(dis[(1 << n) - 1] == 0x3f3f3f3f) puts("-1");
	else cout << dis[(1 << n) - 1] << endl;
  return 0;
}
