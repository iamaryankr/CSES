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
 
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window
 
 
//DONT OVERTHINKKK 
const int mxN = 2e5 + 1;

vector<int> adj[mxN];
vector<int> depth(mxN);
vector<int> dp(mxN);
//dp(i) is the distance of the farthest node from the node i

void depthDfs(int node, int par){
  depth[node] = 0;
  for(auto it: adj[node]){
    if(it != par){
      depthDfs(it, node);
      depth[node] = max(depth[node], 1 + depth[it]);
    }
  }
}

void dfs(int node, int par, int partialans_par){
  vector<int> prefMax, suffMax;
  
  for(auto it: adj[node]){
    if(it != par){
      prefMax.push_back(depth[it]);
      suffMax.push_back(depth[it]);
    }
  }
  int n = prefMax.size();
  for(int i=1; i<n; i++) prefMax[i] = max(prefMax[i], prefMax[i-1]);
  for(int i=n-2; i>=0; i--) suffMax[i] = max(suffMax[i], suffMax[i+1]);

  int cno = 0;
  for(auto it: adj[node]){
    if(it != par){
      int leftans = (cno==0 ? -INF : prefMax[cno-1]);
      int rightans = (cno==n-1 ? -INF : suffMax[cno+1]);
      int partialans_node = 1 + max({leftans, rightans, partialans_par});

      dfs(it, node, partialans_node);
      cno ++;
    }
  }
  dp[node] = max(depth[node], 1 + partialans_par);
}

void solve(){
  int n;
  cin >> n;
  for(int i=2; i<=n; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  depthDfs(1, 0);
  dfs(1, 0, -1);

  for(int i=1; i<=n; i++) cout << dp[i] << " " ;
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