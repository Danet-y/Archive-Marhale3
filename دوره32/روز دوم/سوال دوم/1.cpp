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
const int N=100,MX=2e4+23,mod=10256483,mod1 = 1e9+7;
vector<int> adj[N];
int fac[N];
int inv[N];
int di[N];
int de[N];
vector<int> seen(N);
int pwe(int a, int b, int md = mod){int res = 1; while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
void modplus(int &j,int y){(j+=y)>=mod && (j-=mod);}
bool seenprime(int n){bool fl = 1;for (int i = 2; i <= sqrt(n)+1; i++){if(n%i==0){fl = 0;break;}}return fl;}
void printt(bool fl){if(fl==1){cout << "YES";return;}cout << "NO";}
int GCD(int a, int b) {return b?GCD(b,a%b):a;}
int MOD(int a, int b=mod1){ int res = a + b; return (res >= mod? res - mod : res); }
int LCM(int a, int b) {return a/GCD(a,b)*b;}
int lseen(vector<int>& v){if (v.size() == 0) {return 0;} vector<int> tail(v.size(), 0); int szgth = 1; tail[0] = v[0]; for (int i = 1; i < v.size(); i++) {auto b = tail.begin(), e = tail.begin() + szgth; auto it = lower_bound(b, e, v[i]); if (it == tail.begin() + szgth){tail[szgth++] = v[i];}else{*it = v[i];}} return szgth;}
int yay(int n){return (1ull << n);}
int C(int n,int r){return fac[n] * inv[r] % mod * inv[n-r] % mod;}
void build(){fac[0] = 1; inv[0] = pwe(fac[0],mod-2);for(int i = 1 ; i< N ; i ++) {fac[i] = (fac[i-1] * i);inv[i] = pwe(fac[i],mod-2);}}
int cal(vector<int> arr1,vector<int> v,int sz){return memcmp(arr1.data(), v.data(), sz * sizeof(v[0])) == 0;}
int r3(char a)
{
    if(a=='0') return 0;
    if(a=='1') return 1;
    if(a=='2') return 2;
    if(a=='3') return 3;
    if(a=='4') return 4;
    if(a=='5') return 5;
    if(a=='6') return 6;
    if(a=='7') return 7;
    if(a=='8') return 8;
    if(a=='9') return 9;
	return 0;
 
}
int32_t main() 
{
	build();
	int res[11];
	int kar[11];
	int had[11];
	string s = "12536112123";
	for (int i = 0; i < s.length(); i++)
	{
		had[i] = r3(s[i]);
	}
    kar[0]=11,kar[1]=10,kar[2]=7,kar[3]=9,kar[4]=11,kar[5]=7,kar[6]=4,kar[7]=8,kar[8]=10,kar[9]=11,kar[10]=5;
	int ans = 0;
	for (int i = 0; i < 11; i++)
	{
		res[i]=i+1;
	}
	////////////////
	///
	int fl = 1;
    while(fac[11]--)
    {
        fl = 1;
        for(int j = 0; j < 11; j++)
        {
            if(res[j] < had[j] || res[j]> kar[j])
            {
                fl = 0;
				break;
            }
        }
		if(fl==1) ans++;
        next_permutation(res, res+11);
    }
    cout << pwe(ans,4);
}	
