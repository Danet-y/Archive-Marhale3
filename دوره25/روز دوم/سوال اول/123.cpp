#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 10607;
const int maxn = 1e6 + 10;

ll power (ll a , ll b){
	if (b == 0)
		return 1;
	ll x = power(a , b / 2) % mod;
	if (b % 2)
		return x * x % mod * a % mod;
	return x * x % mod;
}
ll dp[maxn] , n;
int main(){
	ios_base :: sync_with_stdio(false) , cin.tie(0) , cout.tie(0);	
	cin >> n;
	dp[2] = 18;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] * 3 % mod + power(2 , i) * power(3 , i - 1) % mod;
	cout << dp[n]  << "\n";
	return 0;
}
