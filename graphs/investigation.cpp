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

void solve(){
  int n, m;
  cin >> n >> m;
  vector<pii> adj[n];
  while(m--){
    int u, v, wt;
    cin >> u >> v >> wt;
    u--, v--;
    adj[u].push_back({v, wt});
  }
  vector<int> minflights(n, INF);
  vector<int> maxflights(n, -INF);
  vector<ll> dist(n, INFF);
  vector<int> routes(n, 0);
  priority_queue<pll, vpll, greater<pll>> pq; 
  pq.push({0, 0});
  dist[0] = 0;
  routes[0] = 1;
  maxflights[0] = 1;
  minflights[0] = 1;

  while(!pq.empty()){
    ll dis = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if(dist[u] < dis) continue;
    
    for(auto it: adj[u]){
      int v = it.first;
      ll wt = it.second;
      if(dist[v] > dis + wt){
        dist[v] = dis + wt;
        routes[v] = routes[u];
        minflights[v] = 1 + minflights[u];
        maxflights[v] = 1 + maxflights[u];
        pq.push({dis + wt, v});
      }
      else if(dist[v] == dis + wt){
        routes[v] = (routes[u] + routes[v])%MOD;
        minflights[v] = min(minflights[v], 1 + minflights[u]);
        maxflights[v] = max(maxflights[v], 1 + maxflights[u]);
      }
    }
  }
  cout << dist[n-1] << " ";
  cout << routes[n-1] << " ";
  cout << minflights[n-1]-1 << " ";
  cout << maxflights[n-1]-1 << nl;
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