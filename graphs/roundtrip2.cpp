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
const int mxN = 1e5+2;
vector<vector<int>> adj;
vector<int> color;
vector<int> par;
int c_start = -1, c_end = -1;

bool dfs(int node){
  color[node] = 1;

  for(auto it: adj[node]){
    if(color[it] == 0){ // unvisited
      par[it] = node;
      if(dfs(it)) return true;
    }
    else if(color[it]==1) { //detects the node where it came from
      c_start = it, c_end = node;
      return true;
    }
  }
  color[node] = 2;
  return false;
}
void solve(){
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  
  while(m--){
    int u, v; 
    cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
  }
  par.resize(n);
  for(int i=0; i<n; i++) par[i] = i;
  color.assign(n, 0);

  for(int i=0; i<n; i++){
    if(color[i] == 0 && dfs(i)){
      break;
    }
  }
  if(c_start == -1) cout << "IMPOSSIBLE" << nl;
  else{
    vector<int> ans;
    int node = c_end;

    ans.push_back(c_start);
    while(node != c_start){
      ans.push_back(node);
      node = par[node];
    }
    ans.push_back(c_start);
    
    reverse(all(ans));
    cout << int(ans.size()) << nl;
    for(auto it: ans) cout << it + 1 << ' ' ;
    cout << nl;
  }
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