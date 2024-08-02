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


void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pll> adj[n];
    while(m--){
        ll u, v, wt;
        cin>>u>>v>>wt;
        u--, v--;
        adj[u].push_back({v, wt});
    }
    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push({0, 0}); //dist, node
    vll dist(n, INFF);
    vll ways(n, 0);
    vll minFlights(n, 0);
    vll maxFlights(n, 0);
    dist[0] = 0, ways[0] = 1, minFlights[0] = 1, maxFlights[0] = 1;

    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        ll dis = x.first;
        ll node = x.second;
        if(dist[node] < dis) continue;

        for(auto it: adj[node]){
            ll adjNode = it.first;
            ll edwt = it.second;
            if(dist[adjNode] > edwt + dis){
                dist[adjNode] = edwt + dis;
                ways[adjNode] = ways[node];
                minFlights[adjNode] = 1 + minFlights[node];
                maxFlights[adjNode] = 1 + maxFlights[node];
                pq.push({dist[adjNode], adjNode});
            }
            else if(dist[adjNode] == edwt + dis){
                ways[adjNode] = (ways[adjNode]+ways[node])%MOD;
                minFlights[adjNode] = min(minFlights[adjNode] , minFlights[node]+1);
                maxFlights[adjNode] = max(maxFlights[adjNode] , maxFlights[node]+1);
            }
        }
    }
    cout << dist[n-1] << " " << ways[n-1] << " " << minFlights[n-1]-1 << " " << maxFlights[n-1]-1;
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