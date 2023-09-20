#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int l[N], r[N];
int main(){
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int t;
  scanf("%d", &t);
  while(t--){
    int n, k, ans = 0x3f3f3f3f;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &l[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &r[i]);
    int tot = 0, tt = 0;
		for(int i = 1; i <= n; i++) {
    	if(r[i] - l[i] + 1 > 1) tot += r[i] - l[i] + 1;
    	else tt++;
    	if(tot + tt < k) continue;
    	if(tot < k && tot + tt >= k){
    		//puts("AAA");
    		ans = min(ans, r[i] + (k - tot) * 2 + (i - tt) * 2);
			}
			if(tot >= k) {
				ans = min(ans, r[i] - (tot - k) + (i - tt) * 2);
				break;
			}
		}
		//cout << tot << ' ' << tt << endl;
		printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans);
  }
  return 0;
}
