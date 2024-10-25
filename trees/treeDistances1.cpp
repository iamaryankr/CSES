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


const int mxN = 2e5 + 5;;
vector<int> adj[mxN];
vector<int> depth(mxN);
vector<int> dp(mxN);
//dp(u) is distance of farthest node from u

void depth_dfs(int u, int par){
  depth[u] = 0;
  for(auto v: adj[u]){
    if(v != par){
      depth_dfs(v, u);
      make_max(depth[u], depth[v] + 1);
    }
  }
}
//dp(u) = max(depth(u), 1 + partial_ans(par/u))

void dfs(int u, int par, int par_ans){
  vector<int> prefmax, suffmax;
  for(auto v: adj[u]){
    if(v != par){
      int childans = depth[v];
      prefmax.push_back(childans);
      suffmax.push_back(childans);
    }
  }
  int sz = prefmax.size();
  for(int i=1; i<sz; i++) make_max(prefmax[i], prefmax[i-1]);
  for(int i=sz-2; i>=0; i--) make_max(suffmax[i], suffmax[i+1]);

  int cno = 0;
  for(auto v: adj[u]){
    if(v != par){
      int lans = (cno == 0 ? -INF : prefmax[cno-1]);
      int rans = (cno == sz-1 ? -INF : suffmax[cno+1]);
      int new_par_ans = 1 + max({lans, rans, par_ans});

      dfs(v, u, new_par_ans);
      cno ++;
    }
  }
  dp[u] = max(depth[u], 1 + par_ans);
}
void solve(){
  int n;
  cin >> n;
  for(int i=0; i<n-1; i++){
    int u, v;
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  depth_dfs(0, -1); //evalutating the depths of each node
  dfs(0, -1, -1); //calculating from the parents ans including the partial ans
  //dp(0) == depth(0);

  for(int i=0; i<n; i++) cout << dp[i] << " ";
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