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
 
 
//bellman ford for neg cycle and also printing it
 
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> adj[n];
    vector<vector<ll>> edges;
    while(m--){
        ll u, v, wt;
        cin>>u>>v>>wt;
        u--; v--;
        adj[u].push_back({v, wt});
        edges.push_back({u, v, wt});
    }
    vector<ll> dist(n, INFF);
    dist[0] =0;
    for(int i=0; i<n; i++){
        for(auto it: edges){
            ll u = it[0], v = it[1], wt = it[2];
            if(dist[u]!=INFF){
                dist[v] =  min(dist[v], dist[u] + wt);
            }
        }
    }
    bool ok = true;
    vector<ll> par(n, -1); 
    for(int i=0; i<n; i++){
        for(auto it: edges){
            ll u = it[0], v = it[1] , wt = it[2];
            if(dist[u]!=INFF){
                ll x = dist[v];  
                dist[v] = min(dist[v], dist[u]+wt);
                if(dist[v] != x){
                    ok = false;
                    par[v] = u;
                }
            }
        }
    }
    if(ok) no;
    else{
        yes;
        ll x = 0;
        for(int i=0; i<n ;i++){
            if(par[i]!=-1){
                x = i;
                break;
            }
        }
        vector<ll> ans;
        unordered_set<ll> st;
        while(st.find(x)==st.end()){
            ans.push_back(x);
            st.insert(x);
            x = par[x];
        }
        ans.push_back(x);
        reverse(all(ans));
        unordered_set<ll> final;
        for(auto it: ans){
            cout << it+1 << " " ;
            if(final.find(it) != final.end()) break;
            final.insert(it);
        }
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