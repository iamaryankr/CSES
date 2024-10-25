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
 
void dfs(int node, vector<int> radj[], vi &nodesFromN, vi& vis){
  vis[node] = 1;
  nodesFromN.pb(node);
  for(auto v: radj[node]){
    if(!vis[v]) dfs(v, radj, nodesFromN, vis);
  }
}
 
void solve(){
  int n, m;
  cin >> n >> m;
  vector<array<int,3>> edges;
  vector<int> radj[n];
  while(m--){
    int u, v, wt;
    cin >> u >> v >> wt;
    u--, v--;
    edges.pb({u, v, -wt});
    radj[v].pb(u);
  }
  vector<ll> dist(n, INFF);
  dist[0] = 0;
  for(int i=0; i<n-1; i++){
    for(auto it: edges){
      int u = it[0], v = it[1], wt = it[2];
      if(dist[u] != INFF && dist[u] + wt < dist[v])
        dist[v] = dist[u] + wt;
    }
  }
  set<int> negcycle;
  for(auto it: edges){
    int u = it[0], v = it[1], wt = it[2];
      if(dist[u] != INFF && dist[u] + wt < dist[v]){
        dist[v] = dist[u] + wt;
        negcycle.insert(v);
      }
  }
  vector<int> nodesFromN;
  vector<int> vis(n, 0);
  dfs(n-1, radj, nodesFromN, vis);
  bool ok = false;
  for(auto it: nodesFromN){
    if(negcycle.find(it) != negcycle.end()){
      ok = true; 
      break;
    }
  }
  if(ok) cout << -1 << nl;
  else cout << -dist[n-1] << nl;
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