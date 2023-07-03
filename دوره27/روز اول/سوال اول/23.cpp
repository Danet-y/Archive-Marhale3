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
const int N=123,MX=2e4+23,mod=10067,mod1 = 1e9+7;
int dp[N][N];
int inv[N], fac[N];
int pwe(int j,int p) {int ret=1;for(;p;p>>=1,j=1LL *j * j%mod1) if(p&1) ret=1LL  * ret  * j % mod1;return ret;}
void modplus(int &j,int y){(j+=y)>=mod && (j-=mod);}
bool isprime(int n){bool fl = 1;for (int i = 2; i <= sqrt(n)+1; i++){if(n%i==0){fl = 0;break;}}return fl;}
void printt(bool fl){if(fl==1){cout << "YES";return;}cout << "NO";}
int GCD(int a, int b) {return b?GCD(b,a%b):a;}
int LCM(int a, int b) {return a/GCD(a,b)*b;}
int lis(vector<int>& v){if (v.size() == 0) {return 0;} vector<int> tail(v.size(), 0); int szgth = 1; tail[0] = v[0]; for (int i = 1; i < v.size(); i++) {auto b = tail.begin(), e = tail.begin() + szgth; auto it = lower_bound(b, e, v[i]); if (it == tail.begin() + szgth){tail[szgth++] = v[i];}else{*it = v[i];}} return szgth;}
int yay(int n){return (1ull << n);}
int C(int n, int k) { return (((inv[k]*inv[n-k])%mod1)*fac[n])%mod1;}
void build(){fac[0] = 1;for (int i=1; i<N; i++) fac[i] = (fac[i-1]*i)%mod1;inv[N-1] = pwe(fac[N-1],mod1-2);for (int i=N-1; i>0; i--) {inv[i-1] = (inv[i]*i)%mod1;}}
int cal(vector<int> arr1,vector<int> v,int sz){return memcmp(arr1.data(), v.data(), sz * sizeof(v[0])) == 0;}
int ans;
int32_t main()
{
	int n,k;
	cin >> n >> k;
    dp[0][0] = 1;
    for(int i = 1; i < n+1; i++)
	{
        for(int i2 = 0; i2 < k+1; i2++)
		{
            int j = i-i2;
            dp[i2][j] = 0;
            if(i2==1) 
				dp[i2][j] = (dp[i2][j] + dp[i2-1][j])%mod;
			int f = dp[i2][j];
            for(int i3 = i2; i3 <= k; i3++)
			{
                if(i-1-i3 >= 0) f =(f + dp[i3][i-1-i3])%mod;
            }
        }
    }
    cout << dp[0][n];
}
