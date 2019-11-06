/** 
 *  Data-Structure: Disjoint-Set-Union   
 *  Resources: https://cp-algorithms.com/data_structures/disjoint_set_union.html
 *  
 *  Description: Using Size/Rank Based Disjoint set Union
 *  Where Size/Rank => total number of nodes int the union (tree) of nodes
 *  and, Size/Rank is used for Path Compression
 **/
#include <vector>
using namespace std;

// Initially all objects are themselves parent of the set they belong in
// and size of set is 1
vector<int> parent;
vector<int> size_arr;
void make_set(int n){
    for(int i=0; i<n; i++){
        parent.push_back(i);
        size_arr.push_back(1);
    }
}

// Find parent of the set and update the parent for all elements in the set
int find_parent(int u){
    if(u==parent[u])
        return u;
    return parent[u]=find_parent(parent[u]);
}

// merge 2 sets of dsu
// Note: The sets in which u and v belong are merged
void union_sets(int u, int v){
    u=find_parent(u);
    v=find_parent(v);
    if(u==v) return; // Both already have the same parent
    if(size_arr[u]<size_arr[v])
        swap(u,v);
    parent[v]=u;
    size_arr[u]+=size_arr[v];
}