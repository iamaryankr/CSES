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

void build_tree(ll *a, ll s, ll e, ll *tree, ll index)
{
	if(s==e){
		tree[index] = a[s];
		return;
	}
	ll mid = (s+e)/2;
	build_tree(a,s,mid,tree,2*index);
	build_tree(a,mid+1,e,tree,2*index+1);
	tree[index] += tree[2*index]+tree[2*index+1];
	return;
}
ll query(ll *tree,ll ss,ll se,ll qs,ll qe ,ll index)
{
	//complete overlap
	if(ss>=qs and se<=qe)
	{
		return tree[index];
	}
	//No Overlap
	if(qe<ss || qs>se)
	return 0;
 
	//partial overlap
	ll mid = (ss + se)/2;
	ll left = query(tree,ss,mid,qs,qe,2*index);
	ll right = query(tree,mid+1,se,qs,qe,2*index+1);
	return left+right;
}
//point update
void point_update(ll  *tree, ll ss,ll se, ll i,ll inc,ll index)
{
	if(i>se || i<ss)
	return;
	if(ss == se)
	{
		tree[index] = inc;
		return;
	}
	ll mid = (ss + se)/2;
	point_update(tree,ss,mid,i,inc,2*index);
	point_update(tree,mid+1,se,i,inc,2*index+1);
	tree[index] = tree[2*index]+tree[2*index+1];
	return;
}
 
void solve()
{
	int n;
	cin>>n;
	
	ll a[2*n+1];
	for(int i=0;i<2*n;i++)
	cin>>a[i];
	ll tree[4*2*n+1]={0};
	
	
	// for(int i=1;i<=4*n;i++)
	// cout<<tree[i]<<endl;
	vector<ll>ans(n+1);
	
	unordered_map<ll,ll>ump;
	for(int k=1;k<=2;k++)
	{
		for(int i=0;i<2*n;i++)
		{
			if(ump.find(a[i])!=ump.end())
			{
				int pos = ump[a[i]];
				ump.erase(a[i]);
		
				int nst_sg = query(tree,0,2*n-1,pos,i,1);
				ans[a[i]]  += (nst_sg - 1);
				// update with one
				point_update(tree,0,2*n-1,pos,0,1);
			}
			else
			{
				ump[a[i]] = i;
				point_update(tree,0,2*n-1,i,1,1);
			}
		}
		ump.clear();
		memset(tree,0,sizeof(tree));
		reverse(a,a+2*n);
	}
 
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<" ";
	cout<<endl;
 
}
  
 
int main()
{
	ios_base::sync_with_stdio(false); 
    	cin.tie(NULL); 
 
    ll t=1;
	 // cin>>t;
	while(t--)
	{  
      solve();
    }
 
	return 0;
}