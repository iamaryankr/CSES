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
int dp[mxN][2];

//dp(u, 0)-> maxm poss edges s.t no edge from (u, v);
//dp(u, 1)-> maxm poss edges s.t we have 1 edges from (u, v);

void dfs(int node, int par){
  dp[node][1] = dp[node][0] = 0;

  bool isLeaf = true;
  for(auto it: adj[node]){
      if(it != par){
          isLeaf = false;
          dfs(it, node);
      }
  }
  if(isLeaf) return;

  vector<int> pref, suff;
  for(auto it: adj[node]){
    if(it != par){
      pref.push_back(max(dp[it][0], dp[it][1]));
      suff.push_back(max(dp[it][0], dp[it][1]));
    }
  }
  int n = pref.size();
  for(int i=1; i<n; i++) pref[i] = pref[i-1] + pref[i];
  for(int i=n-2; i>=0; i--) suff[i] = suff[i+1] + suff[i];

  int maxi = -1e9;
  int cno = 0;
  for(auto it: adj[node]){
    if(it != par){
      int leftans = (cno==0 ? 0 : pref[cno-1]);
      int rightans = (cno==n-1 ? 0 : suff[cno+1]);
      maxi = max(maxi,  1 + leftans + dp[it][0] + rightans);
      cno ++ ;
    }
  }
  dp[node][0] = suff[0];
  dp[node][1] = maxi;
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

  dfs(1, 0);
  cout << max(dp[1][0], dp[1][1]) << nl;
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