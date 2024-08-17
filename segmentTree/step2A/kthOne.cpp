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
 
int gcd(int a, int b){ return (b ? gcd(b, a % b) : a);}
int lcm(int a, int b){ return (a*b/gcd(a,b)); }
 
int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};
string path_grid = "URDL";
bool valid(int i, int j, int n, int m) {return (i>=0 && i<n && j>=0 && j<m); }
 
const int maxN = 5000000+1;
const int MOD = 1e9+7;
const int N = 1e5+1;
const int INF = 1e9;
const ll INFF = 1e16;
 
 
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window
 
 
//DONT OVERTHINKKK 

//General seg tree template

class segTree{
public:
    int size = 1;
    vector<int> values;
    int neutral_ele = 0;
    //constructor
    segTree(int n){
        while(size < n) size*= 2;
        values.resize(2*size);
    }

    //merge function for child nodes to get ans for parent
    int merge(int a, int b){
        return a+b;
    }
    //assigning int to a node val
    int make_int(int v){
        return v;
    }
    //building the tree with the vector a
    void build(vi &a, int node, int low, int high){
        if(low+1 == high){
            if(low < int(a.size())) values[node] = make_int(a[low]);
            return;
        }
        int mid = (low+high)>>1;
        build(a, 2*node+1, low, mid);
        build(a, 2*node+2, mid, high);
        values[node] = merge(values[2*node+1], values[2*node+2]);
    }
    void build(vi &a){
        build(a, 0, 0, size);
    }

    //building the set function
    void set(int i, int v, int node, int low, int high){
        if(low+1 == high){
            values[node] = make_int(v);
            return;
        }
        int mid = (low+high)>>1;
        if(i<mid) set(i, v, 2*node+1, low, mid);
        else set(i, v, 2*node+2, mid, high);

        values[node] = merge(values[2*node+1], values[2*node+2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    //finding kth one
    int find(int k, int node, int low, int high){
        if(low+1 == high) return low;
        int mid = (low+high)>>1;
        int val = values[2*node+1]; //left child value
        //compare the values
        if(k < val){
            return find(k, 2*node+1, low, mid);
        }
        return find(k-val, 2*node+2, mid, high);
    }
    int find(int k){
        return find(k, 0, 0, size);
    }
};

void solve(){
    int n , q;
    cin >> n >> q;
    vi a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    segTree st(n);
    st.build(a);

    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int i;
            cin >> i;
            a[i] = !a[i];
            st.set(i, a[i]);
        }
        else if(op==2){
            int k;
            cin >> k;
            cout << st.find(k) << nl;
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