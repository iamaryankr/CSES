//iamaryankr
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pob pop_back
#define sq(x) x*x
#define cube(x) x*x*x
#define all(x) (x).begin(), (x).end()
#define debugV(v) for(int i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<endl;
#define debug(x) cout<< #x << " = " << x << endl;
#define debugMat(v) for(int i=0; i<v.size(); i++){ for(int j=0; j<v[0].size(); j++){ cout << v[i][j] << " ";} cout << nl;}
#define nl "\n"
#define ff first;
#define ss second;
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl

typedef long double ld;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef map<int,int> mii;

int gcd(int a, int b){ return (b ? gcd(b, a % b) : a); }
int lcm(int a, int b){ return (a*b/gcd(a,b)); }

int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}
const int maxN = 5000000+1;
const int MOD = 1e9+7;
const int N = 1e5+1;
const int INF = 1e9;
const ll INFF = 1e16;


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window


//tweak in bellman ford 
//bellman ford is for min dist to destination, 
//this question asks for maximum dist to dest

void dfs(ll node, ll par, vector<ll> &reachable, vector<vector<ll>> &radj, vector<ll> &vis){
    if(!vis[node]){
        vis[node] = 1;
        reachable.push_back(node);
        for(auto it: radj[node]){
            if(it != par) dfs(it, node, reachable, radj, vis);
        }
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> adj[n];
    vector<pair<pair<ll,ll>, ll>> edges;
    for(int i=0; i<m; i++){
        ll u,v,wt;
        cin>>u>>v>>wt;
        u--, v--;
        edges.push_back({{u, v}, -wt});
        adj[u].push_back({v, -wt});
    }
    vector<ll> dist(n, INFF);
    dist[0] = 0;
    for(int i=0; i<n-1; i++){
        for(auto it: edges){
            ll u =  it.first.first;
            ll v = it.first.second;
            ll wt = it.second;
            if(dist[u]!=INFF && dist[u]+wt < dist[v]){
                dist[v] = min(dist[v], dist[u]+wt);
            }
        }
    }
    set<ll> temp;
    for(int j=0; j<m; j++){
        ll u = edges[j].first.first;
        ll v = edges[j].first.second;
        ll wt = edges[j].second;
        if(dist[u]!= INFF){
            ll x= dist[v];
            dist[v] = min(dist[v], dist[u]+wt);
            if(x!=dist[v]) temp.insert(v);
        }
    }   

    vector<vector<ll>>  radj(n);
    for(int i=0; i<m; i++){
        ll u = edges[i].first.first;
        ll v = edges[i].first.second;
        radj[v].push_back(u);
    }
    vector<ll> reachable;
    vector<ll> vis(n, 0);
    dfs(n-1, -1, reachable, radj, vis);
    bool ok = true;
    for(auto it: reachable){
        if(temp.find(it) != temp.end()){
            ok = false;
            break;
        }
    }
    if(ok) cout << -dist[n-1] << nl;
    else cout << -1 << nl;
}
   
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}