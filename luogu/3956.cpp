#include<bits/stdc++.h>
using namespace std;
const int zh[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int N = 1005;
int M[N][N], vis[N][N], dis[N][N];
struct Node{
	int x, y, cos, col, tes;
};
int main(){
	freopen("3956.in", "r", stdin);
	freopen("3956.out", "w", stdout);
	int m, n;
	cin >> m >> n;
	for(int i = 1; i <= n; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		if(c == 0) c = 2;
		M[x][y] = c; 
	}
	queue<Node> q;
	q.push((Node){1, 1, 0, M[1][1], 0});
	memset(dis, 0x3f, sizeof(dis));
	dis[1][1] = 0;
	while(q.size()){
		Node tmp = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int dx = tmp.x + zh[i][0], dy = tmp.y + zh[i][1];
			if(dx > m || dx < 1 || dy > m || dy < 1) continue;
			if(dis[dx][dy] <= tmp.cos) continue;
			if(M[dx][dy] == tmp.col) q.push((Node){dx, dy, tmp.cos, M[dx][dy], 0}), dis[dx][dy] = tmp.cos;
			else {
				if(M[dx][dy] == 0) {
					if(dis[dx][dy] <= tmp.cos + 2 || tmp.tes == 1) continue;
					q.push((Node){dx, dy, tmp.cos + 2, M[tmp.x][tmp.y], 1});
					dis[dx][dy] = tmp.cos + 2;
				} 
				else if(dis[dx][dy] + 1 > dis[tmp.x][tmp.y]){
					q.push((Node){dx, dy, tmp.cos + 1, M[dx][dy], 0});
					dis[dx][dy] = tmp.cos + 1;
				}
			} 
		}
	}
	cout << (dis[m][m] == 0x3f3f3f3f ? -1 : dis[m][m]) << endl;
	return 0;
}

