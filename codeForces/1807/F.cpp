#include<bits/stdc++.h>
using namespace std;
int ans = 0, ok = 0;
int n, m;
bool vis[5][25005];
void dfs(int x0, int y0, int x1, int y1, int op){
	if(ok == 1 || ok == -1) return ;
	if(ans >= 1e5){
		ok = -1;
		return ;
	} 
	switch(op){
		case 1:{
			if(x0 + y0 == x1 + y1 && y1 <= y0){
				ok = 1;
				return ;
			} 
			break;
		}
		case 2:{
			if(y0 - x0 == y1 - x1 && y1 >= y0){
				ok = 1;
				return ;
			}
			break;
		}
		case 3:{
			if(x0 + y0 == x1 + y1 && y1 >= y0){
				ok = 1;
				return ;
			} 
			break;
		}
		case 4:{
			if(y0 - x0 == y1 - x1 && y1 <= y0){
				ok = 1;
				return ;
			}
			break;
		}
	}
	//cout << x0 << ' ' << y0 << ' ' << op << endl;
	ans++;
	switch(op){
		case 1:{
			if(n - x0 <= y0 - 1){
				y0 -= (n - x0);
				x0 = n;
				if(y0 == 1 && x0 == n) dfs(x0, y0, x1, y1, 3);
				else dfs(x0, y0, x1, y1, 4);
			}
			else {
				x0 += (y0 - 1);
				y0 = 1;
				dfs(x0, y0, x1, y1, 2);
			}
			break;
		}
		case 2:{
			if(n - x0 <= m - y0){
				y0 += (n - x0);
				x0 = n;
				if(y0 == m && x0 == n) dfs(x0, y0, x1, y1, 4);/**/
				else dfs(x0, y0, x1, y1, 3);
			}
			else {
				x0 += (m - y0);
				y0 = m;
				dfs(x0, y0, x1, y1, 1);
			}
			break;
		}
		case 3:{
			if(x0 - 1 <= m - y0){
				y0 += (x0 - 1);
				x0 = 1;
				if(y0 == m && x0 == 1) dfs(x0, y0, x1, y1, 1);/**/
				else dfs(x0, y0, x1, y1, 2);
			}
			else {
				x0 -= (m - y0);
				y0 = m;
				dfs(x0, y0, x1, y1, 4);
			}
			break;
		}
		case 4:{
			if(x0 - 1 <= y0 - 1){
				y0 -= (x0 - 1);
				x0 = 1;
				if(y0 == 1 && x0 == 1) dfs(x0, y0, x1, y1, 2);/**/
				else dfs(x0, y0, x1, y1, 1);
			}
			else {
				x0 -= (y0 - 1);
				y0 = 1;
				dfs(x0, y0, x1, y1, 3);
			}
			break;
		}
	}
}
int main(){
	freopen("F.in", "r", stdin);
	freopen("F.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		int x0, x1, y0, y1, op;
		ans = 0, ok = 0;
		string s;
		cin >> n >> m >> x0 >> y0 >> x1 >> y1 >> s;
		if(s == "DL") op = 1;
		if(s == "DR") op = 2;
		if(s == "UR") op = 3;
		if(s == "UL") op = 4;
		dfs(x0, y0, x1, y1, op);
		cout << (ok == 1 ? ans : -1) << endl;
	}
	return 0;
}

