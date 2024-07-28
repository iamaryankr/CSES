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



//finding 'k' minimum distances from source to target
//dijkstra with modification

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> adj[n];
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        u--, v--;
        adj[u].push_back({v, wt});
    }

    priority_queue<pll, vpll, greater<pll>> pq;
    priority_queue<ll> maxheap[n];

    pq.push({0, 0}); //dist, node
    maxheap[0].push(0);
    while(!pq.empty()){
        ll dis = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if(dis > maxheap[node].top()) continue;
        for(auto it: adj[node]){
            int adjNode = it.first, wt = it.second;
            ll temp = dis + wt;
            if((int)maxheap[adjNode].size() < k){
                maxheap[adjNode].push(temp);
                pq.push({temp, adjNode});
            }
            else if(maxheap[adjNode].top() > temp){
                maxheap[adjNode].pop();
                maxheap[adjNode].push(temp);
                pq.push({temp, adjNode});
            }
        }
    }
    vector<ll> ans;
    while(!maxheap[n-1].empty()){
        ans.push_back(maxheap[n-1].top());
        maxheap[n-1].pop();
    }
    reverse(all(ans));
    for(auto it: ans) cout << it << " ";
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