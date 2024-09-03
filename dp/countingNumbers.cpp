//iamaryankr
#include<bits/stdc++.h>

using namespace std; 

#define pb push_back
#define pob pop_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define stprc cout << setprecision(12) << fixed
#define debugV(v) cout<<#v<<" = [ "; for(int i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<"]"<<nl;
#define debug(x) cout<< #x << " = " << x << endl;
#define debugMat(v) for(int i=0; i<v.size(); i++){ for(int j=0; j<v[0].size(); j++){ cout << v[i][j] << " ";} cout << nl;}
#define fr(i, a, n) for(int i=a; i<n; i++)
#define nl "\n"
#define ff first
#define ss second
#define yes cout<<"YES"<< nl
#define no cout<<"NO"<< nl

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef map<int,int> mii;
 
template <typename T>
void make_min(T& a, const T& b){ a = min(a, b);}
template <typename T>
void make_max(T& a, const T& b){ a = max(a, b);}
 
int gcd(int a, int b){ return (b ? gcd(b, a % b) : a); }
int lcm(int a, int b){ return (a*b/gcd(a,b)); }
int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};
const string path_grid = "URDL";
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}
 
const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFF = 1e18;
 

//try thinking Binary search(on ans), Bit manipulation,
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window, Topo sort, dijkstra..
//Dp, Dp, Dp, Dp

//-------------------------------------main-code-------------------------------------------------------------------------------------------------------------------------------------------------------


const ll mxN = 19;
ll dp[mxN][mxN][2][2];

ll dfs(string &s, int n, int prev, bool leadingZeros, bool tight){
  if(n == 0) return 1;
  if(prev != -1 && dp[n][prev][leadingZeros][tight] != -1) return dp[n][prev][leadingZeros][tight];

  int lb = 0;
  int ub;
  if(tight == false) ub = 9;
  else ub = s[s.size() - n] - '0';

  ll ans = 0;
  for(int dig = lb; dig <= ub; dig ++){
    if(dig == prev && leadingZeros==false) continue;
    else ans += (dfs(s, n-1, dig, leadingZeros&(dig==0), tight&(dig==ub)));
  }
  return dp[n][prev][leadingZeros][tight] = ans;
}

void solve(){
  ll a, b;
  cin >> a >> b;
  string aa = to_string(a-1);
  string bb = to_string(b);

  //dp(n, prev, lz, tight) is the state
  //n digit number
  //prev is the digit which was of the last index element 
  //leading_zeros are telling if we had zeroes on previous index
  //tight represents the bound that the number must be smaller than b;

  memset(dp, -1, sizeof(dp));
  ll ans1 = dfs(bb, bb.size(), -1, true, true);
  memset(dp, -1, sizeof(dp));
  ll ans2 = dfs(aa, aa.size(), -1, true, true);

  cout << ans1 - ans2 << nl;
}


//DONT OVERTHINKKK 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0; 
}
