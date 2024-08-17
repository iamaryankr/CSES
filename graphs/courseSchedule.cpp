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
const int mxN = 1e5 + 2;
vector<int> adj[mxN];
vector<int> topo;
vector<int> vis(mxN, 0);

void dfs(int node){
  vis[node] = 1;

  for(auto it: adj[node]){
    if(!vis[it]) dfs(it);
  }

  topo.push_back(node);
}
void solve(){
  int n, m;
  cin >> n >> m;
  while(m--){
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
  }
  for(int i=0; i<n; i++){
    if(!vis[i]) dfs(i);
  }
  reverse(all(topo));
  map<int, int> mp;
  for(int i=0; i<int(topo.size()); i++) mp[topo[i]] = i;

  bool ok = true;
  for(int i=0; i<n; i++){
    for(auto it: adj[i]){
      if(mp[it] <= mp[i]){
        ok = false;
        break;
      }
    }
    if(!ok) break;
  }
  
  if(!ok){
    cout << "IMPOSSIBLE" << nl;
    return;
  }
  for(auto it: topo) cout << it + 1 << " ";
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