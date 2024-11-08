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
  


//FORD FULKERSON method
const int mxN = 5e2 + 5;

int n, m;
ll adj[mxN][mxN], order[mxN][mxN];
int par[mxN], vis[mxN];

bool reachable(){
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  q.push(0);
  vis[0] = 1;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v=0; v<n; v++){
      if(adj[u][v] && !vis[v]){
        vis[v] = 1;
        par[v] = u;
        q.push(v);
      }
    }
  }
  return vis[n - 1] == true;
}
void solve(){
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      adj[i][j] = 0;
      order[i][j] = 0;
    }
  }
  while(m--){
    int u, v;
    cin >> u >> v; u -- , v -- ;
    adj[u][v] = adj[v][u] = 1;
    order[u][v] = order[v][u] = 1;
  }

  int u, v;
  while(reachable()){
    ll flow = INFF;
    v = n - 1;
    while(v != 0){
      u = par[v];
      flow = min(flow, adj[u][v]);
      v = u;
    }
    v = n - 1;
    while(v != 0){
      u = par[v];
      adj[u][v] -= flow;
      adj[v][u] += flow;
      v = u;
    }
  }
  reachable();
  vector<pii> ans;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(vis[i] && !vis[j] && order[i][j]){
        ans.push_back(MP(i, j));
      }
    }
  }
  cout << int(ans.size()) << nl;
  for(auto it: ans) cout << it.first + 1 << " " << it.second + 1 << nl;
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