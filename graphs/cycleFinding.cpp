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

//bellman ford for neg cycle and also printing it
 
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edges;
    vector<ll> dist(n, 0); //dont put INFF, as all nodes are to be explored
    vector<ll> par(n, -1); 
    while(m--){
        ll u, v, wt;
        cin>>u>>v>>wt;
        u--; v--;
        edges.push_back({u, v, wt});
    }
    for(int i=0; i<n-1; i++){
      for(auto it: edges){
        int u = it[0], v = it[1], wt = it[2];
        if(dist[u] + wt < dist[v]){
          dist[v] = dist[u] + wt;
          par[v] = u;
        }
      }
    }
    int x = -1;
    for(auto it: edges){
        int u = it[0], v = it[1], wt = it[2];
        if(dist[u] + wt < dist[v]){
          dist[v] = dist[u] + wt;
          par[v] = u;
          x = v;
        }
      }
    if(x==-1) cout << "NO" << nl;
    else{
        cout << "YES" << nl;
        for (int i = 0; i < n; ++i) x = par[x];

        vector<int> cycle;
        int node = x;
        while(par[node] != node){
            cycle.push_back(node);
            node = par[node];
            if (node == x && cycle.size() > 1) break;
        }
        cycle.pb(x);
        reverse(all(cycle));
        if(cycle.size()==1){
          cout << cycle[0]+1 << " " << cycle[0]+1 << nl;
          return;
        }
        for (int v : cycle) cout << v+1 << ' ';
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