#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define ll long long  
using namespace std;
const int maxn = 200;
const int mod = 10607;
ll modd = 1e9 + 7;
ll b[maxn][maxn] , c[maxn][maxn] , ans[maxn][maxn] , a[maxn][maxn];
bool mark[maxn][maxn];
ll power (ll a , ll b){
	   if (b == 0)
			 return 1;
	   ll x = power(a , b / 2) % modd;
	   if (b % 2)
			 return x * x % modd * a % modd;
	   return x * x % modd;
}
int main() {
	ios_base :: sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	int n = 100;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			c[i][j] = power(7 , i) * power(3 , j) % modd + 1e8;
	b[1][n] = b[1][1] = b[n][n] = b[n][1] = 1;
	for (int _ = 0; _ < 200; _++){
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (b[i][j] >= 1){
					if (i + 1 <= n)
						a[i + 1][j]++;
					if (j + 1 <= n)
						a[i][j + 1]++;
					if (i - 1 >= 1)
						a[i - 1][j]++;
					if (j - 1 >= 1)
						a[i][j - 1]++;
				}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				b[i][j] += a[i][j] , a[i][j] = 0 , ans[i][j]++;
	}
	for (int _ = 1; _ <= 1e4 + 10; _++){
		ll p = 1e17;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				int u = 0;
				if (!mark[i + 1][j] && i + 1 <= n && b[i + 1][j] > 0)
					u++;
				if (!mark[i - 1][j] && i - 1 >= 1 && b[i - 1][j] > 0)
					u++;
				if (!mark[i][j - 1] && j - 1 >= 1 && b[i][j - 1] > 0)
					u++;
				if (!mark[i][j + 1] && j + 1 <= n && b[i][j + 1] > 0)
					u++;
				if (!mark[i][j] && u > 0){
					ll x = c[i][j] - b[i][j];
					if (x % u == 0)
						x /= u;
					else
						x /= u , x++;
					p = min(p , x);
				}
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				int u = 0;
				if (!mark[i + 1][j] && i + 1 <= n && b[i + 1][j] > 0)
					u++;
				if (!mark[i - 1][j] && i - 1 >= 1 && b[i - 1][j] > 0)
					u++;
				if (!mark[i][j - 1] && j - 1 >= 1 && b[i][j - 1] > 0)
					u++;
				if (!mark[i][j + 1] && j + 1 <= n && b[i][j + 1] > 0)
					u++;
				if (!mark[i][j] && u > 0){
					a[i][j] += p * u;
					ans[i][j] += p;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++){
				b[i][j] += a[i][j];
				if (b[i][j] >= c[i][j])
					mark[i][j] = 1;
				a[i][j] = 0;
			}
	}
	ll ans2 = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (b[i][j] >= c[i][j])
				ans2 += ans[i][j] , ans2 %= mod;
	cout << ans2 << "\n";
	cout << ans2 * ans2 % mod * ans2 % mod << "\n";
	return 0;
}
//The_End
//Game Over :D
