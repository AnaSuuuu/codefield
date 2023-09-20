#include<bits/stdc++.h>
using namespace std;
char s[10];
const int zh[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ans = 0;
bool is_non_prime(int x) {
	if(x == 1) return true;
	for(int i = 2; i * i <= x; i++) if(x % i == 0) return true;
	return false;
}
void dfs(int pos, int num) {
	if(pos != 8) {
		if(num % 2 == 0) return ;
		if(num % 5 == 0) return ;
	}
	if(pos < 7) {
		if(is_non_prime(num % 100)) return;
		if((num % 100 > 31) || (num % 100 == 0)) return ;
	}
	if(pos < 5) {
		if(is_non_prime(num % 10000)) return ;
		if((num / 100 % 100 > 12) || (num / 100 % 100 == 0)) return ;
		if(num % 100 > zh[num / 100 % 100]) return ;
	}
	if(pos < 1) {
		if(is_non_prime(num)) return ;
		if(num / 10000 == 0) return ;
		if((num / 100 % 100 == 2) && (num % 100 == 29)) {
			if(num / 10000 % 4) return ;
			if((num / 10000 % 100 == 0) && (num / 10000 % 400)) return ;
		}
	}
	//cout << num << ' ' << pos << endl;
	if(pos == 0) {
		//cout << num << endl;
		ans++;
		return ;
	}
	if(s[pos] == '-') {
		for(int i = 0; i <= 9; i++){
			num = num + i * pow(10, 8 - pos);
			dfs(pos - 1, num);
			int kdl = pow(10, 8 - pos);
			num = num % kdl;
		}
	}
	else num = num + (s[pos] - '0') * pow(10, 8 - pos), dfs(pos - 1, num);
}
int main(){
	freopen("5440.in", "r", stdin);
	freopen("5440.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		scanf("%s", s + 1);
		bool ok = 1;
		for(int i = 1; i <= 8; i++) 
			if(s[i] != '-') {
				ok = 0;
				break;
			}
		if(ok) {
			puts("55157");
			continue;
		}
		ans = 0;
		dfs(8, 0);
		cout << ans << endl;
	}
	//cout << is_non_prime(701) << is_non_prime(11310701) << endl;
	return 0;
}

