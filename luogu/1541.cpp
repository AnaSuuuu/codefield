#include<bits/stdc++.h>
using namespace std;
const int N = 355;
int a[N], num[5];
int f[45][45][45][45];
int main(){
	freopen("1541.in", "r", stdin);
	freopen("1541.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		num[x]++;
	}
	f[0][0][0][0] = a[1];
	for(int aa = 0; aa <= num[1]; aa++){
		for(int bb = 0; bb <= num[2]; bb++){
			for(int cc = 0; cc <= num[3]; cc++){
				for(int dd = 0; dd <= num[4]; dd++){
					int pos = aa + 2 * bb + 3 * cc + 4 * dd + 1;
					if(aa) f[aa][bb][cc][dd] = max(f[aa][bb][cc][dd], f[aa - 1][bb][cc][dd] + a[pos]);
					if(bb) f[aa][bb][cc][dd] = max(f[aa][bb][cc][dd], f[aa][bb - 1][cc][dd] + a[pos]);
					if(cc) f[aa][bb][cc][dd] = max(f[aa][bb][cc][dd], f[aa][bb][cc - 1][dd] + a[pos]);
					if(dd) f[aa][bb][cc][dd] = max(f[aa][bb][cc][dd], f[aa][bb][cc][dd - 1] + a[pos]);
				}
			}
		}
	}	
	cout << f[num[1]][num[2]][num[3]][num[4]] << endl;
	return 0;
}

