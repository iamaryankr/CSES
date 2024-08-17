//iamaryankr
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(), (x).end()
#define debugV(v) cout<<#v<<" = [ "; for(int i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<"]"<<nl;
#define debug(x) cout<< #x << " = " << x << endl;
#define debugMat(v) for(int i=0; i<v.size(); i++){ for(int j=0; j<v[0].size(); j++){ cout << v[i][j] << " ";} cout << nl;}
#define fr(i, a, n) for(int i=a; i<n; i++)
#define nl "\n"
#define ff first;
#define ss second;
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
 
typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef map<int,int> mii;
 
int gcd(int a, int b){ return (b ? gcd(b, a % b) : a); }
int lcm(int a, int b){ return (a*b/gcd(a,b)); }
 
int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};
const string path_grid = "URDL";
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}

const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFF = 1e18;
 
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window
 
 
//DONT OVERTHINKKK 

const int mxN = 1e6 + 2;
vector<vll> dp(mxN, vll(2));

void solve(){
  int n;
  cin >> n;
  
  //dp(i, linked) -> ways to fill from ith pos to nth
  //bool linked -> == 0 if (i-1)th tiles are 2 separate tiles
  //bool linked -> == 1 if (i-1)th tiles are 1 single tile
  //final ans is == (dp(1, 0) + dp(1, 1));
  //dp(i, 0) ==  1. dont extend any tile -> dp(i+1, 0) + dp(i+1, 1);
  //             2. extend both the tiles -> dp(i+1, 0);
  //             3. extend only 1 tile -> 2*dp(i+1, 0);
  //dp(i, 1) == has only 2 ops which are op1 and op4th -> dp(i+1, 1)

  dp[n][0] = dp[n][1] = 1;

  for(int i=n-1; i>=0; i--){
    ll op1 = (dp[i+1][1] + dp[i+1][0])%MOD;
    ll op2 = dp[i+1][0];
    ll op3 = (2*dp[i+1][0])%MOD;
    ll op4 = dp[i+1][1];

    dp[i][0] = (op1 + op2 + op3)%MOD;
    dp[i][1] = (op1 + op4)%MOD;
  }
  cout << (dp[1][1]+dp[1][0])%MOD << nl;
}
  
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // cout << setprecision(12) << fixed; 
  int t = 1;
  cin >> t;
  while (t--) {
      solve();
  }
  return 0; 
}