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

class segTree {
public:
    int size = 1;
    vector<int> tree;

    segTree(int n) {
        while (size < n) {
            size *= 2;
        }
        tree.resize(2 * size, 0);
    }

    int merge(int a, int b) {
        return a + b;
    }

    void build(vector<ll>& a, int x, int low, int high) {
        if (high - low == 1) {
            if (low < (int)a.size()) tree[x] = a[low];
            return;
        }
        int mid = (low + high) / 2;
        build(a, 2 * x + 1, low, mid);
        build(a, 2 * x + 2, mid, high);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<ll>& a) {
        build(a, 0, 0, size);
    }

    void update(int x, int low, int high, int i, int v) {
        if (high - low == 1) {
            tree[x] = v;
            return;
        }
        int mid = (low + high) / 2;
        if (i < mid) update(2 * x + 1, low, mid, i, v);
        else update(2 * x + 2, mid, high, i, v);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, int v) {
        update(0, 0, size, i, v);
    }

    int query(int x, int low, int high, int l, int r) {
        if (low >= r || high <= l) return 0;
        if (low >= l && high <= r) return tree[x];
        int mid = (low + high) / 2;
        int lq = query(2 * x + 1, low, mid, l, r);
        int rq = query(2 * x + 2, mid, high, l, r);
        return merge(lq, rq);
    }

    int query(int l, int r) {
        return query(0, 0, size, l, r);
    }
};

void solve() {
    ll n;
    cin >> n;
    n *= 2;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> freq(n, 0);
    vector<ll> lastOccurrence(n + 1, -1);
    segTree st(n);
    st.build(freq);
    vector<ll> ans(n / 2, 0);

    for (int i = 0; i < n; i++) {
        if (lastOccurrence[a[i]] == -1) {
            lastOccurrence[a[i]] = i;
        } else {
            ans[a[i] - 1] = st.query(lastOccurrence[a[i]], i);
            st.update(lastOccurrence[a[i]], 1);
        }
    }

    for (int i = 0; i < n / 2; i++) cout << ans[i] << " ";
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
