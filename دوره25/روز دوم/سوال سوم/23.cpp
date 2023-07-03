#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
const int maxn = 1e6 + 10;
const int mod = 10607;
int dp[maxn];
ll power (ll a , ll b){
	if (b == 0)
		return 1;
	ll x = power(a , b / 2) % mod;
	if (b % 2)
		return x * x % mod * a % mod;
	return x * x % mod;
}
int main(){
	dp[0] = 1 , dp[1] = 2;
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 2; i < maxn; i++)
		dp[i] = dp[i - 1] + dp[i - 2] , dp[i] %= mod;
	for (int x = 2; x <= n; x++){
		ll p = 1;
		for (int i = 1; i <= n; i++){
			if (i % x != 0){
				int cnt = 0;
				for (int j = i; j <= n; j *= x)
					cnt++;
				p *= dp[cnt];
				p %= mod;
			}
		}
		/*cout << x << " " << g[x].size() << "\n";
		for (auto u : g[x])
			cout << u << " ";
		cout << "\n";*/
		p = power(2 , n) - p + mod * 5, p %= mod;
		ans += p;
		ans %= mod;
	}
	cout << ans << "\n";
}
