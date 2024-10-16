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
#define MP make_pair
 
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
 
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers, bitmask
//sliding window


//Binary lifting for findind the ansectors
int n, l, timer;
vector<vector<int>> adj;
vector<int> tin, tout;
vector<vector<int>> up;


void dfs(int u, int par){
    tin[u] = ++timer;
    up[u][0] = par;
    for(int i=1; i<=l; i++){
        if(up[u][i-1]!=-1)
            up[u][i] = up[up[u][i-1]][i-1];
        else up[u][i] = -1;
    }
    for(auto v: adj[u]){
        if(v!=par) dfs(v, u);
    }
    tout[u] = ++timer;
}

//is u an ancestor of v
bool isAncestor(int u, int v){
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int lca(int u, int v){
    if(isAncestor(u, v)) return u;
    if(isAncestor(v, u)) return v;

    for(int i=l; i>=0; i--){
        if(!isAncestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}
void preprocess(int root){
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int> (l+1, -1));
    dfs(root, root);
}
int getKthAncestor(int node, int k) {
    int curr = node;
    for(int i=0; i<=l; i++){
        if(k&(1<<i)){
            curr = up[curr][i];
            if(curr==-1) return -1;
        }
    }
    return curr;
}
void solve(){

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