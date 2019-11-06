/** 
 *  Algorithm: Strongly Connected Components (Detect and convert Cycle to component)
 *  Tutorials:
 *  https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/
 *  https://cp-algorithms.com/graph/strongly-connected-components.html
**/

#include <bits/stdc++.h>

#define fori(i,n) for(int i=0; i<n; i++)

using namespace std;

stack<int> stk;
vector<int> component_nodes;

void doDFS(vector<vector<int>> adjlist, vector<int>& visited, int source){
    visited[source]=1;
    for(auto j=adjlist[source].begin(); j!=adjlist[source].end(); j++){
        if(!visited[*j]){
            doDFS(adjlist,visited,*j);
        }
    }
    stk.push(source);
}

void doDFS2(vector<vector<int>> adjlist, vector<int>& visited, int source){
    int j;
    visited[source]=1;
    component_nodes.push_back(source+1);
    for(auto j=adjlist[source].begin(); j!=adjlist[source].end(); j++){
        if(!visited[*j]){
            doDFS2(adjlist,visited,*j);
        }
    }
}



int main(){
    int n,m,tempi,tempj,i,j;
    vector<int> visited; // 0 based indexing for computation

    cin >> n >> m;
    vector<vector<int>> adjlist(n), adjlist_rev(n); // graph and graph-transpose
    
    while(m--){
        cin >> tempi >> tempj; // input starts from 1
        tempi--; tempj--;       // convert to 0 based for computations
        adjlist[tempi].push_back(tempj);
        adjlist_rev[tempj].push_back(tempi);
    }


// Initial DFS
    visited = vector<int>(n,0);
    fori(i,n)
        if(!visited[i]){
            doDFS(adjlist,visited,i);
        }

// Final DFS until all nodes visited
    visited=vector<int>(n,0);
    while(stk.size()){
        while(stk.size() && visited[stk.top()])
            stk.pop();
        
        if(!stk.size())
            break;

        i=stk.top();
        stk.pop();
        visited[i]=1;

        doDFS2(adjlist_rev,visited,i);

        cout << "COMPONENT with node " << component_nodes[0] << ": ";
        fori(j,component_nodes.size())
            cout << component_nodes[j] << " ";
        cout << endl;
        component_nodes.clear();
    }
    return 0;
}
