//iamaryankr
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(), (x).end()
#define debugV(v) cout<<#v<<" = [ "; for(int i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<"]"<<nl;
#define debug(x) cout<< #x << " = " << x << endl;
#define debugMat(v) for(int i=0; i<v.size(); i++){ for(int j=0; j<v[0].size(); j++){ cout << v[i][j] << " ";} cout << nl;}
#define fr(i, val, n) for(int i=val; i<n; i++)
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
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}

const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFF = 1e18;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers, bitmask
//sliding window


//DONT OVERTHINKKK//
const int mxN = 1001;
int dp[mxN][mxN];

int dfs(int i, int j, vector<string> &s){
  if(i == 0 && j == 0){
    return (s[0][0] == '.');
  }
  if(dp[i][j] != -1) return dp[i][j];

  int up = 0;
  if(i>=1 && s[i-1][j] == '.' ) up = dfs(i-1, j, s);
  int left = 0;
  if(j>=1 && s[i][j-1] == '.') left = dfs(i, j-1, s);

  return dp[i][j] = (up + left)%MOD;
}

void solve(){
  int n;
  cin >> n;
  memset(dp, -1, sizeof(dp));

  vector<string> s(n);
  for(int i=0; i<n; i++) cin >> s[i];

  if(s[0][0] == '*' || s[n-1][n-1] == '*'){
    cout << 0 << nl;
    return;
  }
  cout << dfs(n-1, n-1, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}