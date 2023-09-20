#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> e;
int a[N];
void Tarjan(){
	
}
int main(){
	freopen("3387.in", "r", stdin);
	freopen("3387(1).out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
	}
	Tarjan();
	return 0;
}

