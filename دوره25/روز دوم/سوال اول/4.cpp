#include <bits/stdc++.h>
using namespace std;
#define Tof_Io ios_base::sync_with_stdio(false);cin.tie(0) , cout.tie(0);
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define int long long int
#define F first
#define S second
#define tagh2(j) j>>1
#define zarb2(j) j<<1
const int N=1e6+23,MX=2e4+23,mod=10289,mod1 = 1e9+7;
int dp[N];
int inv[N], fac[N];
int pwe(int j,int p) {int ret=1;for(;p;p>>=1,j=1LL *j * j%mod1) if(p&1) ret=1LL  * ret  * j % mod1;return ret;}
void modplus(int &j,int y){(j+=y)>=mod && (j-=mod);}
bool isprime(int n){bool fl = 1;for (int i = 2; i <= sqrt(n)+1; i++){if(n%i==0){fl = 0;break;}}return fl;}
void printt(bool fl){if(fl==1){cout << "YES";return;}cout << "NO";}
int GCD(int a, int b) {return b?GCD(b,a%b):a;}
int LCM(int a, int b) {return a/GCD(a,b)*b;}
int lis(vector<int>& v){if (v.size() == 0) {return 0;} vector<int> tail(v.size(), 0); int szgth = 1; tail[0] = v[0]; for (int i = 1; i < v.size(); i++) {auto b = tail.begin(), e = tail.begin() + szgth; auto it = lower_bound(b, e, v[i]); if (it == tail.begin() + szgth){tail[szgth++] = v[i];}else{*it = v[i];}} return szgth;}
int MOD2(int a, int b){return (a%b + b) % b;}
int yay(int n){return (1ull << n);}
int fact(int k){int ans=1;for (int i=1; i<=k; i++) ans = (ans*i)%mod1;return ans;}
int ifact(int k){return pwe(fact(k), mod1-2);}
int C(int n, int k){ return (((ifact(k)*ifact(n-k))%mod1)*fact(n))%mod1; }
void build(){fac[0] = 1;for (int i=1; i<N; i++) fac[i] = (fac[i-1]*i)%mod1;inv[N-1] = pwe(fac[N-1],mod1-2);for (int i=N-1; i>0; i--) {inv[i-1] = (inv[i]*i)%mod1;}}
int cal(vector<int> arr1,vector<int> v,int sz){return memcmp(arr1.data(), v.data(), sz * sizeof(v[0])) == 0;}
const int MAXN = 1e6 + 69 , MOD = 1e9 + 7 , DELTA = 10607 ;

int n = 2015 , ans , cnt[MAXN] , temp[MAXN] ;

int exp(int base , int power) {
	if ( power == 0 )
		return 1 ;
	int half = exp(base , power >> 1) ;
	int res = (half * half) % DELTA ;
	if ( power & 1 )
		res = (res * base) % DELTA ;
	return res ;
}
int get(int L , int R) {
	L %= DELTA , R %= DELTA ;
	int up = (R * (R + 1)) % DELTA ;
	up = (up * exp(2 , DELTA - 2)) % DELTA ;
	int low = ((L - 1) * L) % DELTA ;
	low = (low * exp(2 , DELTA - 2)) % DELTA ;
	return (up - low + DELTA) % DELTA ;
}
int32_t main() {
	cin.tie(0) ; cout.tie(0) ;
	cnt[0] = 1 ;
	for ( int it = 1 ; it <= n ; it ++ ) {
		for ( int j = 0 ; j < 2069 ; j ++ )
			temp[j + 1] += cnt[j] , temp[j + 1] %= DELTA ;
		for ( int j = 0 ; j <= 2069 ; j ++ )
			cnt[j] += temp[j] % DELTA , cnt[j] %= DELTA , temp[j] = 0 ;
	}
	int R = (exp(2 , n) - 1 + DELTA) % DELTA ;
	for ( int i = n ; i >= 0 ; i -- ) {
		int res = (exp(2 , i) * get(R - cnt[i] + 1 , R)) % DELTA ;
		ans = (ans + res) % DELTA ;
		R = ((R - cnt[i]) + DELTA) % DELTA ;
	}
	cout << ans << "\n" ;
}

