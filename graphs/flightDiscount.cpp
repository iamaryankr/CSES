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


//dijkstra with state analysis
//usually only 2 states in dijkstra, node and its distance

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> adj[n];
    while(m--){
        ll u,v, wt;
        cin>>u>>v>>wt;
        u--,  v--;
        adj[u].push_back({v, wt});
    }
    priority_queue<vector<ll>, vector<vector<ll>>, 
    greater<vector<ll>>> pq;
    vector<vector<ll>> dist(n, vector<ll> (2, INFF));
    //dist[i][j] is dist with discount and without
    dist[0][1] = 0;
    dist[0][0] = 0;
    pq.push({0, 0, 1}) ; //{dist, node, available};
    
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        ll dis = x[0], u = x[1], canAvail = x[2];
        if(dist[u][canAvail] < dis) continue;
        for(auto it: adj[u]){
            ll v = it.first, wt = it.second;
            if(canAvail==1){
                if(dist[v][1] > dis + wt){
                    dist[v][1] = dis + wt;
                    pq.push({dist[v][1], v, 1});
                }
                if(dist[v][0] > dis + wt/2){
                    dist[v][0] = dis + wt/2;
                    pq.push({dist[v][0], v, 0});
                }

            }
            else{
                if(dist[v][0] > dis + wt){
                    dist[v][0] = dis + wt;
                    pq.push({dist[v][0], v, 0});
                }
            }
        }
    }
    cout << min(dist[n-1][0], dist[n-1][1]) << nl;
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