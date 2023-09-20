#include<bits/stdc++.h>
using namespace std;
const int N = 4e4 + 5;
int phi[N], fac[N], pri[N];
int tot, euler[N];
int main(){
	freopen("2158.in","r",stdin);
	freopen("2158.out","w",stdout);
	int n;
	cin >> n;
	if(n == 1){
		puts("0");
		return 0;
	}
	phi[1] = 1;
	for(int i = 2; i <= n; i++){
		if(fac[i] == 0){
			pri[++tot] = i;
			fac[i] = i;
			euler[i] = i - 1;
		}
		for(int j = 1; j <= tot; j++){
			if(pri[j] > fac[i] || pri[j] * i > n) break;
			fac[pri[j] * i] = pri[j];
			if(pri[j] == fac[i]) euler[i * pri[j]] = pri[j] * euler[i];
			else euler[i * pri[j]] = (pri[j] - 1) * euler[i];
		}
		phi[i] = phi[i - 1] + euler[i];
	} 
	//for(int i = 1; i <= n; i++) cout << phi[i] << ' ';
	//cout << endl;
	cout << (phi[n - 1]<<1|1) << endl;
	return 0;
}

