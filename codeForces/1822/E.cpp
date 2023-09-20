#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
char s[N];
int cnt[30], las[30];
int tt[30];
int main(){
	freopen("E.in", "r", stdin);
	freopen("E.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		memset(cnt, 0 ,sizeof(cnt));
		memset(las, 0, sizeof(las));
		memset(tt, 0, sizeof(tt));
		int n, maxn = 0;
		scanf("%d", &n);
		scanf("%s", s + 1);
		if(n & 1){
			puts("-1");
			continue;
		}
		for(int i = 1; i <= n; i++){
			cnt[s[i] - 'a']++;
			if(cnt[s[i] - 'a'] > maxn) maxn = cnt[s[i] - 'a'];
		}
		if(maxn > n / 2){
			puts("-1");
			continue;
		}
		int tot = 0;
		for(int i = 1; i <= n / 2; i++){
			if(s[i] == s[n - i + 1])	tt[s[i] - 'a']++, tot++;
		}
		int ok = 0;
		for(int i = 0; i <= 25; i++){
			if(tt[i] * 2 > tot){
				cout << tt[i] << endl;
				ok = 1;
				break;
			}
		} 
		if(ok) continue;
		else cout << (tot + 1) / 2 << endl;
		/*ll ans = 0;
		for(int j = 1; j <= 30; j++){
			sort(tt, tt + 26);
			int  i;
			for(i = 0; i < 25 && tt[i] == 0; i++){
				;
			}
			if(i == 25 ){
				ans += tt[i];
				break;
			}
			else {
				ans += tt[i];
				tt[25] -= tt[i];
				tt[i] = 0;
			}
		}
		printf("%lld\n", ans);*/
	}
	return 0;
}

