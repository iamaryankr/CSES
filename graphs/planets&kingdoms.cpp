//iamaryankr
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define pob pop_back
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
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}
 
const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFF = 1e18;
 
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers, bitmask
//sliding window
 
 
//application of kosaraju's algorithm
 
void dfs(int node, vi adj[], vi& finish, ll& timer, vi &vis){
    vis[node] = 1;  
    for(auto it: adj[node]){
        if(!vis[it]) dfs(it, adj, finish, timer, vis);
    }
    finish[node] = timer++;
}
 
void dfs2(int node, vi &vis, vi radj[], int king, vi &kingdoms){
    vis[node] = 1;
    kingdoms[node] = king;
    for(auto it: radj[node]){
        if(!vis[it]) dfs2(it, vis, radj, king, kingdoms);
    }
}
 
void solve(){
    int n, m; 
    cin >> n >> m;
    vector<int> adj[n], radj[n];
    while(m--){
        int a, b;
        cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    vi finish(n, -1);
    vi vis(n, 0);
    ll timer = 0;
 
    for(int i=0; i<n; i++){
        if(!vis[i]) dfs(i, adj, finish, timer, vis);
    }
 
    vi order(n);
    for(int i=0; i<n; i++) order[i] = i;
    sort(order.begin(), order.end(), [&](int a, int b){
        return finish[a] > finish[b];
    });
 
    vis.clear();
    vis.assign(n, 0);
    int cnt = 0;
 
    vi kingdoms(n, -1);
    for(int i=0; i<n; i++){
        if(!vis[order[i]]){
            cnt++;
            dfs2(order[i], vis, radj, cnt, kingdoms);
        }
    }
 
    cout << cnt << nl;
    for(auto it: kingdoms) cout << it <<" ";
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