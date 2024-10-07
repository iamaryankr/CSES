//iamaryankr
#include<bits/stdc++.h>
using namespace std; 
using namespace chrono;

#define pb push_back
#define pob pop_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define stprc cout << setprecision(12) << fixed
// #define debugV(v) cout<<#v<<" = [ "; for(int i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<"]"<<nl;
// #define debug(x) cout<< #x << " = " << x << endl;
// #define debugMat(v) for(int i=0; i<v.size(); i++){ for(int j=0; j<v[0].size(); j++){ cout << v[i][j] << " ";} cout << nl;}
#define fr(i, a, n) for(int i=a; i<n; i++)
#define nl "\n"
#define ff first
#define ss second
#define yes cout<<"YES"<< nl
#define no cout<<"NO"<< nl
#define setbits(x) __builtin_popcount(x)
#define lsb(x) __builtin_ctz(x) //trailing zeros
#define msb(x) (31-lsb(x))  //pos of leftmost 1
#define firstsetbit(x) (__builtin_ffs(x)-1) //0-indexed
#define readV(a) for(int i=0; i<(int)a.size(); i++) cin >> a[i];
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


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" = "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

//print statements for debugging
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//some funcs
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
//fenwick & segment tree

//WRITE STUFF..dont mindSolve

//-------------------------------------main_code-------------------------------------------------------------------------------------------------------------------------------------------------------

const int mxN = 1e5 + 1;
ll dp[21][2][4];
 
ll dfs(string &s, int n, bool tight, int nz){
  if(nz < 0) return 0;
  if(n == 0 && nz >= 0) return 1;
  if(dp[n][tight][nz] != -1) return dp[n][tight][nz];
 
  int ub = (tight ? (s[s.size() - n]-'0') : 9);
 
  ll ans = 0;
  for(int dig = 0; dig <= ub; dig ++){
    if(dig == 0) ans += dfs(s, n-1, tight&(dig==ub), nz);
    else ans += dfs(s, n-1, tight&(dig==ub), nz-1);
  }
 
  return dp[n][tight][nz] = ans;
}
void solve() {
  ll l, r;
  cin >> l >> r;
  string L = to_string(l-1);
  string R = to_string(r);
  debug(L);
  memset(dp, -1, sizeof(dp));
  ll ans1 = dfs(R, R.size(), true, 3);
  debug(ans1);
  memset(dp, -1, sizeof(dp));
  ll ans2 = dfs(L, L.size(), true, 3);
  
  cout << ans1 - ans2 << nl;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
  #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto start1 = high_resolution_clock::now();
    int t = 1;
    cin >> t;
    while(t--) solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
  #ifndef ONLINE_JUDGE
    cerr << "Time(ms): " << duration . count() / 1000 << endl;
  #endif
}
