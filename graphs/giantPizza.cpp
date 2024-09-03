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
vector<vector<int>> adj(mxN), radj(mxN);
vector<int> kingdom(mxN);
vector<int> vis;
vector<int> topo;


//2 - SAT problem

//fill the toposort 
void dfs1(int u){
  vis[u] = 1;
  for(auto v: adj[u]){
    if(!vis[v]) dfs1(v);
  }
  topo.push_back(u);
}

//mark the kingdoms(scc)
void dfs2(int u, int& cnt){
  vis[u] = 1;
  kingdom[u] = cnt;
  for(auto v: radj[u]){
    if(!vis[v]) dfs2(v, cnt);
  }
}
void solve(){ 
  int n, m;
  cin >> n >> m;
  //build the graph from conjecture
  for(int i=0; i<n; i++){
    char s1, s2;
    int x, y;
    cin >> s1 >> x >> s2 >> y;
    if(s1 == '-') x = 2*m + 1 - x;
    if(s2 == '-') y = 2*m + 1 - y;
    adj[2*m + 1 - x].push_back(y);
    adj[2*m + 1 - y].push_back(x);
    radj[x].push_back(2*m + 1 - y);
    radj[y].push_back(2*m + 1 - x);
  }

  vis.assign(2*m+1, 0);
  for(int i=1; i<=2*m; i++){
    if(!vis[i]) dfs1(i);
  }
  
  reverse(all(topo));
  vis.clear();
  vis.assign(2*m+1, 0);
  int cnt = 0;

  for(auto u: topo){
    if(!vis[u]){
      cnt ++ ;
      dfs2(u, cnt);
    }
  }
  
  //finally print the result
  vector<int> res(m+1);
  for(int i=1; i<=m; i++){
    if(kingdom[i] == kingdom[2*m + 1 - i]){
      cout << "IMPOSSIBLE" << nl;
      return;
    }
    res[i] = (kingdom[i] > kingdom[2*m + 1 - i]);
  }
  for(int i=1; i<=m; i++){
    cout << (res[i] ? '+' : '-') << " ";
  }
  cout << nl;
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
