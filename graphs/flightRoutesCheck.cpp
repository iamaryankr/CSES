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
const ll INFF = 1e16;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers, bitmask
//sliding window


vi vdfs1;
vi vdfs2;

int cnt1=0, cnt2=0;
void dfs1(int node, vi &vis1, vi adj[]){
    vis1[node] = 1;
    for(auto it: adj[node]){
        if(!vis1[it]) dfs1(it, vis1, adj);
    }
}
void dfs2(int node, vi &vis2, vi radj[]){
    vis2[node] = 1;
    for(auto it: radj[node]){
        if(!vis2[it]) dfs2(it, vis2, radj);
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> radj[n];

    while(m--){
        int u, v;
        cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    vector<int> vis1(n, 0);
    vector<int> vis2(n, 0);

    for(int i=0; i<n; i++){
        if(!vis1[i]) {
            vdfs1.push_back(i);
            dfs1(i,  vis1, adj);
            cnt1++;
        }
    }
    for(int i=0; i<n; i++){
        if(!vis2[i]) {
            vdfs2.push_back(i);
            dfs2(i,  vis2, radj);
            cnt2++;
        }
    }
    if(vdfs1==vdfs2 && cnt1==1){
        cout << "YES" << nl;
    }
    else{
        cout << "NO" << nl;
        if(cnt1>1){
            cout << vdfs1[0]+1 << " " << vdfs1[1]+1 << nl;
            return ; 
        }
        if(cnt2>1){
            cout << vdfs2[1]+1 << " " << vdfs2[0]+1 << nl;
            return ;
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