//iamaryankr
#include<bits/stdc++.h>
using namespace std; 
using namespace chrono;

#define pb push_back
#define pob pop_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define stprc cout << setprecision(12) << fixed
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
template <class T> void _print(vector<pair<int, T>> v) {cerr << "[ "; for (const auto& i : v) {cerr << "{" << i.first << ", " << i.second << "} ";}cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//some funcs
template <typename T>
void make_min(T& a, const T& b){ a = min(a, b);}
template <typename T>
void make_max(T& a, const T& b){ a = max(a, b);}
 
int gcd(int a, int b){ return (b ? gcd(b, a % b) : a); }
int lcm(int a, int b){ return (a*b/gcd(a,b)); }
int ceildiv(int x, int y){ return (x + y - 1)/y ;}
int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};
int dr8[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
int dc8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const string path_grid = "URDL";
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}
 
const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFF = 1e18;



//try thinking Binary search(on ans), Bit manipulation,
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding okdow, Topo sort, dijkstra..
//Dp, Dp, Dp, Dp
//fenwick & segment trees


//-------------------------------------main_code-------------------------------------------------------------------------------------------------------------------------------------------------------
//WRITE STUFF..dont mindSolve

const int mxN = 1e5 + 2;
vector<int> adj[mxN];
vector<bool> black(mxN);
ll dp_black[mxN], dp_white[mxN];

void dfs(int u, int par){
  for(auto v: adj[u]){
    if(v != par) dfs(v, u);
  }

  if(black[u]){
    dp_white[u] = 0;
    ll blacks = 1;
    for(auto v: adj[u]){
      if(v != par){
        blacks = (blacks*(dp_white[v] + dp_black[v]))%MOD;
      }
    }
    dp_black[u] = blacks;
  }
  else{
    vector<ll> pref, suff, blacknodes, whitenodes;
    for(auto v: adj[u]){
      if(v != par){
        blacknodes.push_back(dp_black[v]);
        whitenodes.push_back(dp_white[v]);
      }
    }
    if(whitenodes.empty()){
      dp_white[u] = 1;
      dp_black[u] = 0;
      return;
    }
    pref.push_back(whitenodes[0]  + blacknodes[0]);
    for(int i=1; i<int(whitenodes.size()); i++){
      pref.push_back((1LL*pref[i-1]*(blacknodes[i] + whitenodes[i]))%MOD);
    }
    suff = vector<ll> (whitenodes.size(), 0);
    suff[whitenodes.size() - 1] = (blacknodes.back() + whitenodes.back());
    for(int i=int(whitenodes.size())-2; i>=0; i--){
      suff[i] = (1LL*suff[i+1]*(blacknodes[i] + whitenodes[i])%MOD);
    }
    dp_white[u] = pref.back();
    dp_black[u] = 0;

    int cno = 0;
    for(auto v: adj[u]){
      if(v == par) continue;
      ll left = (cno == 0 ? 1 : pref[cno-1]);
      ll right = (cno == whitenodes.size()-1 ? 1 : suff[cno+1]);
      dp_black[u] = (dp_black[u] +(1LL*left*right%MOD)*dp_black[v])%MOD;
      cno ++;
    }
  }
}
void solve(){
  int n;
  cin >> n;
  for(int i=0; i<n-1; i++){
    int p;
    cin >> p;
    adj[i+1].push_back(p);
    adj[p].push_back(i+1);
  }
  for(int i=0; i<n; i++){
    int isblack;
    cin >> isblack;
    black[i] = isblack;
  }

  dfs(0, -1); 
  cout << dp_black[0] % MOD << nl;
}

//WRITE STUFF..dont mindSolve
//-------------------------------------main_code-------------------------------------------------------------------------------------------------------------------------------------------------------




int main(){
  #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
  #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    auto start1 = high_resolution_clock::now();
    int t = 1;
    // cin >> t;
    // precompute();
    // calcfact();
    // calcinvfact();
    // stprc;
    for(int test=0; test<t; test++){
        #ifndef ONLINE_JUDGE
          cerr << "-> Test: " << test + 1 << nl;
        #endif
      // cout << "Case #" << test + 1 << ": ";
      solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
  #ifndef ONLINE_JUDGE
    cerr << "Time(ms) " << duration . count() / 1000 << nl;
  #endif
}
