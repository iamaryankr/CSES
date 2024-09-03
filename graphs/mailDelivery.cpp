//iamaryankr
#include<bits/stdc++.h>
using namespace std; 

#define pb push_back
#define pob pop_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
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
 

//-------------------------------------main-code-------------------------------------------------------------------------------------------------------------------------------------------------------

//try thinking Binary search(on ans), Bit manipulation,
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window, Topo sort, dijkstra..
//Dp, Dp, Dp, Dp
 
 
//DONT OVERTHINKKK 


const int mxN = 2e5 + 5;
vector<vector<pii>> adj;
vector<int> path;
vector<int> vis;
vector<int> degree;
 

//BASIC EULERIAN PATH algorithm
void dfs(int u){
  while(!adj[u].empty()){
    int v = adj[u].back().first, ind = adj[u].back().second;
    adj[u].pop_back();
    if(vis[ind]) continue;
    vis[ind] = 1;
    dfs(v);
  }
  path.push_back(u);
}
void solve(){
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  degree.assign(n, 0);
  vis.assign(m, 0); // vis is for the edges

  for(int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    degree[u] ++ , degree[v] ++ ;
  }

  for(int u=0; u<n; u++){
    if(degree[u]&1){
      cout << "IMPOSSIBLE" << nl;
      return;
    }
  }
  dfs(0);

  if(int(path.size()) == m+1){
    for(auto u: path) cout << u + 1 <<  " ";
    cout << nl;
  }
  else cout << "IMPOSSIBLE" << nl;
}
  
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // cout << setprecision(12) << fixed; 
  int t = 1;
  // cin >> t;
  while (t--) {
      solve();
  }
  return 0; 
}
