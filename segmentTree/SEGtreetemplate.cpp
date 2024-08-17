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


//GENERAL SEG TREE 
struct item{
};
class segTree{
public:
    int size = 1;
    vector<item> values;
    item neutral_ele = {};
    //constructor
    segTree(int n){
        while(size < n) size*= 2;
        values.resize(2*size);
    }

    //merge function for child nodes to get ans for parent
    item merge(item a, item b){
    }
    //assigning item to a node val
    item make_item(int v){
    }
    
    //building the tree with the vector a
    void build(vi &a, int node, int low, int high){
        if(low+1 == high){
            if(low < int(a.size())) values[node] = make_item(a[low]);
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
            values[node] = make_item(v);
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

    //finding result in a segment
    item calc(int l, int r, int node, int low, int high){
        if(low>=r || high<=l) return neutral_ele;
        if(low>=l && high<=r) return values[node];

        int mid = (low+high)>>1;
        item left = calc(l, r, 2*node+1, low, mid);
        item right = calc(l, r, 2*node+2, mid, high);
        return merge(left, right);
    }
    item calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
};