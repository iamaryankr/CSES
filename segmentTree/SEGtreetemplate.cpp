//iamaryankr
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
//GENERAL SEG TREE 
//Point updates and Range Queries
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