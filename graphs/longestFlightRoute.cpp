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
 
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window


//longest path to the destination(n) from (1);
//using toposort and reverse adjacency list

vector<int> vis;
vector<int> par;
vector<vector<int>> adj;
vector<vector<int>> radj;
vector<int> dist;
stack<int> stk;

void toposort(int node){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dist[it] = dist[node] + 1;
            par[it] = node;
            toposort(it);
        }
    }
    stk.push(node);
}
void solve(){
    int n,m;
    cin>>n>>m;
    adj.resize(n);
    radj.resize(n);
    while(m--){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    dist.assign(n, 0);
    vis.assign(n, 0);
    par.assign(n, -1);

    toposort(0);
    if(!vis[n-1]) cout << "IMPOSSIBLE" <<nl;
    else{
        while(!stk.empty()){
            int node = stk.top();
            stk.pop();
            for(auto it: radj[node]){
                if(dist[node] < dist[it]+1){
                    par[node] = it;
                    dist[node] = dist[it]+1;
                }
            }
        }
        vector<int> ans;
        ans.push_back(n-1);
        int x = par[n-1];
        while(x!=0){
            ans.push_back(x);
            x = par[x];
        }
        ans.push_back(0);
        reverse(all(ans));
        cout << ans.size() << nl;
        for(auto x: ans) cout << x+1 << " "; 
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