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

//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window
 
 
//DONT OVERTHINKKK 
const int mxN = 2e5 + 5;
vector<int> adj[mxN];
vector<int> tin(mxN), tout(mxN);
vector<vector<int>> up;
int timer, l;
vector<int> pref(mxN, 0);

void binarylift(int u, int par){
  tin[u] = ++timer;
  up[u][0] = par;

  for(int i=1; i<=l; i++){
    if(up[u][i-1] != -1)
      up[u][i] = up[up[u][i-1]][i-1];
    else up[u][i] = -1;
  }
  for(auto v: adj[u]){
    if(v != par) binarylift(v, u);
  }

  tout[u] = ++timer;
}
bool isAncestor(int u, int v){
  return tin[u]<=tin[v] && tout[u]>=tout[v];
}
int lca(int u, int v){
  if(isAncestor(u, v)) return u;
  if(isAncestor(v, u)) return v;

  for(int i=l; i>=0; i--){
    if(up[u][i]!=-1 && !isAncestor(up[u][i], v)) u = up[u][i];
  }
  return up[u][0];
}


void dfs(int u, int par){
  for(auto v: adj[u]){
    if(v!=par){
      dfs(v, u);
      pref[u] += pref[v];
    }
  }
}
void solve(){
  int n, m;
  cin >> n >> m;
  l = ceil(log2(n));
  timer = 0;
  up.assign(n+1, vi(l+1, -1));
  for(int i=2; i<=n; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  binarylift(1, -1);
  while(m--){
    int u, v;
    cin >> u >> v;
    int lca_ = lca(u, v);
    pref[u] ++ ;
    pref[v] ++ ;
    pref[lca_] --;
    pref[up[lca_][0]]--;
  }
  
  dfs(1, 0);
  for(int i=1; i<=n; i++) cout << pref[i] << " ";
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