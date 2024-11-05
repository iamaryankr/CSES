//iamaryankr
#include<bits/stdc++.h>
using namespace std; 
using namespace chrono;
  
#define pb push_back
#define pob pop_back
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define stprc cout << setprecision(12) << fixed
#define rep(i, a, b) for(int i=a; i<b; i++)
#define nl "\n"
#define fr first
#define sc second
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
typedef vector<string> vstr;
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
bool iseven(int n){ return n%2 == 0 ;}
bool isodd(int n){ return n&1 ;}
int ceildiv(int x, int y){ return (x + y - 1)/y ;}
int delrow[4] = {-1, 0, 1, 0};
int delcol[4] = {0, 1, 0, -1};
string path_grid = "URDL";
int dr8[8] = {-1, -1, -1, 0, 0, 1, 1, 1 }; 
int dc8[8] = {-1, 0, 1, -1, 1, -1, 0, 1 };
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}
  
const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFF = 1e18;
  
  
  
//try thinking Binary search(on ans), Bit manipulation,
//jee standard Maths, greedy, BFS, DFS, 2 pointers 
//sliding window, Topo sort, dijkstra..
//Dp, Dp, Dp, Dp
//fenwick & segment trees
  
  
  
  
//-------------------------------------main_code-------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
//WRITE STUFF..dont mindSolve, 
//you can code very quickly if you figure out logic
//Maybe think in reverse??
//DON'T OVERthink

const int mxN = 1e5 + 5;
vector<int> adj[mxN], radj[mxN], dag[mxN]; 
vector<int> k;
vector<int> topo, vis, kingdom, dagtopo;
vector<ll> kingdomval;

void toposort(int u){
  vis[u] = 1;
  for(auto v: adj[u]){
    if(!vis[v]) toposort(v);
  }
  topo.push_back(u);
}

void dfs(int u, int cnt){
  vis[u] = 1;
  kingdom[u] = cnt;
  kingdomval[cnt] += k[u];
  for(auto v: radj[u]){
    if(!vis[v]) dfs(v, cnt);
  }
}

void dagtoposort(int u){
  vis[u] = 1;
  for(auto v: dag[u]){
    if(!vis[v]) dagtoposort(v);
  }
  dagtopo.push_back(u);
}
void solve(){
  int n, m;
  cin >> n >> m;
  k.resize(n);
  for(int i=0; i<n; i++) cin >> k[i];

  while(m--){
    int u, v;
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    radj[v].push_back(u);
  }

  vis.assign(n, 0);
  for(int i=0; i<n; i++){
    if(!vis[i]) toposort(i);
  }
  reverse(all(topo));
  
  vis.assign(n, 0);
  kingdom.assign(n, -1);
  kingdomval.assign(n, 0);
  int cnt = 0;
  for(auto u: topo){
    if(!vis[u]){
      dfs(u, cnt);
      cnt ++;
    }
  }

  for(int u=0; u<n; u++){
    for(auto v: adj[u]){
      int ku = kingdom[u], kv = kingdom[v];
      if(ku != kv){
        dag[ku].push_back(kv);
      }
    }
  }

  vis.assign(cnt, 0);
  for(int i=0; i<cnt; i++){
    if(!vis[i]) dagtoposort(i);
  }
  reverse(all(dagtopo));

  vector<ll> dp(cnt, 0);
  for(int i=0; i<cnt; i++){
    dp[i] = kingdomval[i];
  }
  for(auto u: dagtopo){
    for(auto v: dag[u]){
      dp[v] = max(dp[v], dp[u] + kingdomval[v]);
    }
  }
  cout << *max_element(all(dp)) << nl;
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
    for(int test=1; test<=t; test++){
        #ifndef ONLINE_JUDGE
          cerr << "-> Test: " << test << nl;
        #endif
      // cout << "Case #" << test << ": ";
      solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
  #ifndef ONLINE_JUDGE
    cerr << "Time(ms) " << duration . count() / 1000 << nl;
  #endif
}