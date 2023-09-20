#include <bits/stdc++.h>

#include <utility>

using LL = long long;
using ld = long double;
using ull = unsigned long long;
using Pair = std::pair<int, int>;
using unl = __int128;
#define inf 1'000'000'000
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void write(unl x) {
	if (x > 9)write(x / 10);
	std::cout << char(x % 10 + '0');
}

inline void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    LL sum = 0;
    for (auto &x: a)std::cin >> x, sum += x;
    unl ans = 0;
    for (int i = 0; i < n; i++)ans += ((unl)sum - a[i]) * a[i];
    write(ans / 2), std::cout << '\n';
}

int main() {
//    freopen("1.in", "r", stdin);
//    freopen("2.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    std::cin >> T;
    for (int i = 1; i <= T; i++)solve(i);
    return 0;
}
