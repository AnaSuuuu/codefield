#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int ans[N], tag[N];
int block_num, block_len;
int col[N], hh[N];
void update(int l, int r){
	//cout << col[l] << ' ' << col[r] << endl;
	for(int i = l; i <= min(r, block_len * col[l]); i++)	{
		ans[col[i]] -= hh[i] ^ tag[col[i]];
		hh[i] ^= 1;
		ans[col[i]] += hh[i] ^ tag[col[i]];
	}
	if(col[r] != col[l])
		for(int i = (col[r] - 1) * block_len + 1; i <= r; i++)	{
			ans[col[i]] -= hh[i] ^ tag[col[i]];
			hh[i] ^= 1;
			ans[col[i]] += hh[i] ^ tag[col[i]];
		}
	for(int i = col[l] + 1; i < col[r]; i++)	tag[i] ^= 1, ans[i] = block_len - ans[i];
}
void query(int l, int r){
	int Ans = 0;
	//cout << col[l] << ' ' << col[r] << endl;
	for(int i = l; i <= min(r, block_len * col[l]); i++) 
		Ans += (hh[i] ^ tag[col[i]]);
	if(col[r] != col[l]) 
		for(int i = (col[r] - 1) * block_len + 1; i <= r; i++) Ans += (hh[i] ^ tag[col[i]]);
	for(int i = col[l] + 1; i < col[r]; i++) Ans += ans[i];
	cout << Ans << endl;
}
int main(){
	freopen("3870.in", "r", stdin);
	freopen("3870.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	//puts("AAA");
	block_len = sqrt(n);
	int tmp = 1;
	for(int i = 1; i <= n; i++) col[i] = (tmp * block_len >= i ? tmp : ++tmp);
	block_num = ceil(n / block_len);
	//for(int i = 1; i <= block_num; i++) ans[i] = block_len;
	//for(int i = 1; i <= block_num; i++) cout << ans[i] << ' ';
	//cout << endl;
	//cout << block_num << ' ' << block_len << endl;
	//puts("AAA");
 	for(int i = 1; i <= m; i++){
		int t, a, b;
		cin >> t >> a >> b;
		switch(t){
			case 0:{
				update(a, b);
				break;
			}
			case 1:{
				query(a, b);
				break;
			}
		}
	}
	return 0;
}

