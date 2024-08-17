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
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
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
 
//try thinking Binary search(on ans), BadjNode manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window


//print cycle in a undirected graph

const int mxN = 1e5+2;

// vector<int> color(mxN, -1);
vector<int> adj[mxN];
vector<bool> vis(mxN, 0);
vector<int> parent(mxN, -1);
int cycleStart=-1, cycleEnd=-1;

bool dfs(int node, int par){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(it==par) continue;
        parent[it] = node;
        if(!vis[it]){
            if(dfs(it, node)) return true;
        }
        else if(vis[it]){
            cycleEnd = node;
            cycleStart = it;
            return true;
        }
    }
    return false;
}
void solve(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i=0; i<n; i++){
        if(!vis[i] && dfs(i, parent[i])){
            break;
        }
    }
    if(cycleStart==-1){
        cout << "IMPOSSIBLE" <<nl;
    }
    else{
        vector<int> cycle;
        cycle.pb(cycleStart);
        int node = cycleEnd;
        while(node != cycleStart){
            cycle.pb(node);
            node = parent[node];
        }
        cycle.pb(cycleStart);
        reverse(all(cycle));

        cout << cycle.size() << nl;
        for(auto it: cycle) cout << it+1 << " " ;
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