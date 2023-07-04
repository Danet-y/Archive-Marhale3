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
#define forr(n) for(int i = n ;i>0; i--) 
const int N=1e6+23,MX=2e4+23,mod=10256483,mod1 = 1e9+7;
vector<int> adj[N];
int fac[N];
int inv[N];
int di[N];
int dt[N];
int pwe(int a, int b, int md = mod){int res = 1; while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
void modplus(int &j,int y){(j+=y)>=mod && (j-=mod);}
bool isprime(int n){bool fl = 1;for (int i = 2; i <= sqrt(n)+1; i++){if(n%i==0){fl = 0;break;}}return fl;}
void printt(bool fl){if(fl==1){cout << "YES";return;}cout << "NO";}
int GCD(int a, int b) {return b?GCD(b,a%b):a;}
int MOD(int a, int b=mod1){ int res = a + b; return (res >= mod? res - mod : res); }
int LCM(int a, int b) {return a/GCD(a,b)*b;}
int lis(vector<int>& v){if (v.size() == 0) {return 0;} vector<int> tail(v.size(), 0); int szgth = 1; tail[0] = v[0]; for (int i = 1; i < v.size(); i++) {auto b = tail.begin(), e = tail.begin() + szgth; auto it = lower_bound(b, e, v[i]); if (it == tail.begin() + szgth){tail[szgth++] = v[i];}else{*it = v[i];}} return szgth;}
int yay(int n){return (1ull << n);}
int C(int n,int r){return fac[n] * inv[r] % mod * inv[n-r] % mod;}
void build(){fac[0] = 1; inv[0] = pwe(fac[0],mod-2);for(int i = 1 ; i< N ; i ++) {fac[i] = (fac[i-1] * i)%mod;inv[i] = pwe(fac[i],mod-2);}}
int cal(vector<int> arr1,vector<int> v,int sz){return memcmp(arr1.data(), v.data(), sz * sizeof(v[0])) == 0;}
int32_t main()
{
	int n ;
	cin >> n;
	int m = 0;
	int ans = 0;
    for(int i = 0 ; i < n ; i ++) 
	{
		int k;
		k = 1;
        for(int j = 1 ; j < i+2 ; j ++) 
		{
			k = 1;
            while((k + 1) * j <= i+1) k++;
			bool fl = 0;
            if(k==1)
                fl = 1;
			else
			{
				if(i+1 >= k * (j + 1))
					fl = 1;
				else
				{
					m++;
					di[j]++;
					dt[i]++;
					adj[i].pb(j);
				}
			}
        }
    }
    forr(n)
	{
        if(dt[i] >= di[i]+1) ans = (ans +dt[i] - di[i])%mod;
    }
    cout << pwe(ans , 3);
}
