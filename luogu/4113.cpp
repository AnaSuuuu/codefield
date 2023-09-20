#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int x[N], c[N];
int n, C, m;
int last1[N], last2[N];
struct Node {
	int l, r, id, ans;
}s[N];
inline void in(int &x) {
	x = 0;
	int f = 1;
	char c = getchar();
	while(c > '9' || c < '0') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	x *= f;
}
inline void out(int x) {
	if(x >= 10) out(x / 10); 
	putchar(x % 10 + '0');
}
bool cmp1(Node x, Node y) {
	return x.r < y.r;
}
int lowbit(int x) {
	return x & (-x);
}
void add(int x, int num) {
	for(; x <= n; x += lowbit(x)) c[x] += num;
	return ;
} 
int query(int x) {
	int sum = 0;
	for(; x; x -= lowbit(x)) sum += c[x];
	return sum;
}
bool cmp2(Node x, Node y) {
	return x.id < y.id;
}
int main(){
	freopen("4113.in", "r", stdin);
	freopen("4113.out", "w", stdout);
	in(n); in(C); in(m);
	for(int i = 1; i <= n; i++) in(x[i]);
	for(int i = 1; i <= m; i++) in(s[i].l), in(s[i].r), s[i].id = i;
	sort(s + 1, s + 1 + m, cmp1);
	for(int i = 1; i <= m; i++) {
		//cout << s[i].l << ' ' << s[i].r << endl;
		for(int j = s[i - 1].r + 1; j <= s[i].r; j++) {
			if(last1[x[j]] == 0) last1[x[j]] = j;
			else {
				if(last2[x[j]] == 0) {
					last2[x[j]] = last1[x[j]];
					last1[x[j]] = j;
					add(last2[x[j]], 1);
				}
				else {
					add(last2[x[j]], -1);
					last2[x[j]] = last1[x[j]];
					last1[x[j]] = j;
					add(last2[x[j]], 1);
				}
			}
		}
		s[i].ans = query(s[i].r) - query(s[i].l - 1);
		//for(int i = 1; i <= n; i++) cout << query(i) << ' ';
		//cout << endl;
	}
	sort(s + 1, s + 1 + m, cmp2);
	for(int i = 1; i <= m; i++) out(s[i].ans), puts("");
	return 0;
}

