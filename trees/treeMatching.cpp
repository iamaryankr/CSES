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

const int mxN = 2e5+2 ;

vi adj[mxN];
vvi dp(mxN, vi (2));

void dfs(int node, int par){
    vi suff, pref;
    dp[node][0] = dp[node][1] = 0;

    bool isLeaf = true;
    for(auto it: adj[node]){
        if(it != par){
            isLeaf = false;
            dfs(it, node);
        }
    }
    if(isLeaf) return;

    //computing suffix & prefix ans now
    for(auto it: adj[node]){
        if(it != par){
            pref.push_back(max(dp[it][0], dp[it][1]));
            suff.push_back(max(dp[it][0], dp[it][1]));
        }
    }
    for(int i=1; i<(int)pref.size(); i++) pref[i] += pref[i-1];
    for(int i=(int)suff.size()-2; i>=0; i--) suff[i] += suff[i+1];

    dp[node][0] = suff[0];
    int childno = 0;
    for(auto it: adj[node]){
        if(it!=par){
            int lchild = (childno==0) ? 0 : pref[childno-1];
            int rchild = (childno==(int)suff.size()-1) ? 0 : suff[childno+1];

            dp[node][1] = max(dp[node][1], 1+lchild+rchild+dp[it][0]);
            childno ++;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vi ans(n+1);
    for(int i=2; i<=n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    //0 is if we take don't take that edge
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