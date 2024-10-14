//iamaryankr
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
//GENERAL SEG TREE 
//Point updates and Range Queries
class Node{
public:
    
};
class Segtree{
public:
    int size = 1;
    vector<Node> values;
    Node neutral_ele = {};
    //constructor
    Segtree(int n){
        while(size < n) size*= 2;
        values.resize(2*size);
    }

    //merge function for child nodes to get ans for parent
    Node merge(Node a, Node b){
    }
    //assigning Node to a node val
    Node make_Node(int v){
    }
    
    //building the tree with the vector a
    void build(vi &a, int node, int low, int high){
        if(low+1 == high){
            if(low < int(a.size())) values[node] = make_Node(a[low]);
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
            values[node] = make_Node(v);
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
    Node calc(int l, int r, int node, int low, int high){
        if(low>=r || high<=l) return neutral_ele;
        if(low>=l && high<=r) return values[node];

        int mid = (low+high)>>1;
        Node left = calc(l, r, 2*node+1, low, mid);
        Node right = calc(l, r, 2*node+2, mid, high);
        return merge(left, right);
    }
    Node calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
};