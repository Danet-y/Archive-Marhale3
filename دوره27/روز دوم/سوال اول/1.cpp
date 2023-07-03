// In the name of Allah

#include <bits/stdc++.h>
using namespace std;

typedef long long int	ll;
typedef long double	ld;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;

#define all(x)		(x).begin(),(x).end()
#define len(x)		((ll) (x).size())
#define F		first
#define S		second
#define pb		push_back
#define sep             ' '
#define endl            '\n'
#define Mp		make_pair
#define debug(x)	cerr << #x << ": " <<  x << endl;
#define kill(x)		cout << x << '\n', exit(0);
#define set_dec(x)	cout << fixed << setprecision(x);
#define file_io(x,y)	freopen(x, "r", stdin); freopen(y, "w", stdout);

int n = 50;
const int maxn = 52;
const int mod = 10289;
int a[maxn][maxn];

int rand(ll x, ll m) {
	return (123 * x * x + 1234 * x + 12345) % m;
}

void del(int r) {
	int t = 0;
	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (a[i][j] == -1) continue;
			
			if (t == r) a[i][j] = -1;
			
			t++;
		}
	}
}

ll cal() {
	int t = 0;
	ll output = 0;
	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (a[i][j] == -1) continue;
			
			output += 1ll * a[i][j] * t % mod; output %= mod;
			t++;
		}
	}
	
	return output;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = ((n - i - 1) * n + j + 1);
		}
	}
	
	ll output = 0;
	for (int i = 1; i <= n * n; i++) {
		int t = n * n - i + 1;
		int r = rand(i, t);
		
		output += cal(); output %= mod;
		del(r);
	}
	
	cout << output << endl;
	
	return 0;
}
