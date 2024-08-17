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
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}

const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFF = 1e18;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers, bitmask
//sliding window


//DONT OVERTHINKKK//

const int mxN = 2e5+2;
vector<int> adj[mxN];
vector<int> depth(mxN);
vector<int> ans(mxN);

//evaluating the depth of any node i -> depth[i];
void evaldepth(int node, int par){
    int node_depth = 0;
    for(auto it: adj[node]){
        if(it!= par){
            evaldepth(it, node);
            node_depth = max(node_depth, 1 + depth[it]);
        }
    }
    depth[node] = node_depth;
}

//finding the ans for each node
//ans(i) is max Dist from i'th node to any other node
void dfs(int node, int par, int partial_ans){
    vector<int> pref, suff;
    for(auto it: adj[node]){
        if(it != par){
            pref.push_back(depth[it]);
            suff.push_back(depth[it]);
        }
    }
    for(int i=1; i<pref.size(); i++) pref[i] = max(pref[i], pref[i-1]);
    for(int i=int(suff.size()-2); i>=0; i--) suff[i] = max(suff[i], suff[i+1]);
    
    int childNo = 0;
    for(auto it: adj[node]){
        if(it != par){
            int op1 = (childNo==0 ? -INF : pref[childNo-1]);
            int op2 = (childNo==int(suff.size()-1) ? -INF : suff[childNo+1]);
            int temp = 1 + max(partial_ans, max(op1, op2));
            
            dfs(it, node, temp);
            childNo ++ ;
        }
    }
    ans[node] = 1 + max(partial_ans, (pref.empty() ? -1 : pref.back()));
}

void solve(){
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    evaldepth(1, 0);
    dfs(1, 0, -1);

    for(int i=1; i<=n; i++) cout << ans[i] << " ";
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