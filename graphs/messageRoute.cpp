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

int gcd(int a, int b){ return (b ? gcd(b, a % b) : a); }
int lcm(int a, int b){ return (a*b/gcd(a,b)); }

int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}
const int maxN = 5000000+1;
const int MOD = 1e9+7;
const int N = 2e5+1;
const int INF = 1e9;


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//try thinking Binary search, Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window

//
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u-1].push_back({v-1, 1});
        adj[v-1].push_back({u-1, 1});
    }
    vector<int> dist(n, 1e9), par(n);
    for(int i=0; i<n; i++) par[i] = i;
    dist[0] = 0;
    queue<pair<int,int>> q;      //{node, dist}
    q.push({0, 0});
    while(!q.empty()){
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();
        for(auto it: adj[node]){
            int edwt = it.second;
            int adjnode = it.first;
            if(edwt + dis < dist[adjnode]){
                dist[adjnode] = dis + edwt;
                q.push({adjnode, dis+edwt});
                par[adjnode] = node;
            }
        }
    }
    if(dist[n-1]==1e9) cout << "IMPOSSIBLE" <<nl;
    else{
        cout<< dist[n-1]+1 <<nl;
        vector<int> path;
        int node = n-1;
        while(par[node]!=node){
            path.push_back(node);
            node = par[node];
        }
        path.push_back(0);
        reverse(all(path));
        for(auto it: path) cout << it+1 << " " ;
        cout << nl;
    }
    

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