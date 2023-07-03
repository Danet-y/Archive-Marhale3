#include <bits/stdc++.h> 
#define pb push_back 
#define F first 
#define S second 
#define all(a) a.begin(),a.end() 
#define pii pair<int,int>
#define int long long
#define ld long double
#define mat vector<vector<int> > 
using namespace std ;
const int  maxn =1002, maxq = 1e5 + 10,inf =1e9 + 10 , mod= 10289 ; 
int po(int a ,int b){
  if(b==0)return 1;
  int v = po(a , b/2) ;
  v = v * v % mod ;
  if(b&1)v = (v*a)%mod ;
  return v;
}
int rand(int x , int m){
  return (123*x*x + 1234*x + 12345)%m ;
}
int e[maxn][maxn] , mark[maxn][maxn] , n = 50 ;;
pii tt[maxq] ; 
int cnt= 0  , ans = 0 , t[maxn] ;;
void upd(){
  cnt =0  ;
  memset(t , 0 , sizeof t) ;
  for(int j = 0 ; j < n ; j++){
    for(int i = 0 ; i < n ; i++){
      if(mark[i][j] == 1)continue ;
      e[t[j]][j] = cnt ;
      t[j]++;
      tt[cnt] = {i,j} ;
      cnt++;
    }
  }
}
int dx[] = {1 , 0 , -1 , 0} , dy[] = {0 , 1 , 0 , -1} ;
void dfs(int x ,int y){ 
  mark[x][y] = 1 ;
  for(int i =0 ; i < 4 ; i++){
    int xx = x+dx[i] , yy = y + dy[i] ;
    if(mark[xx][yy] == 1)continue ;
    dfs(xx , yy) ; 
  }
}

signed main(){
  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);


  
  cout << 8914 ; 
}
/*
  vector <pair <int , int > > vec; 
  for(int i = 0  ;i < n*n; i++){
    upd() ;
    int f = rand(i+1+2500 , cnt) ; 
    vec.pb(tt[f]) ;
    mark[tt[f].F][tt[f].S] = 1;
    int x = dfs(tt[f].F , tt[f].S) ; 
    ans = (ans + x*x*x)%mod ; 
  }
*/



