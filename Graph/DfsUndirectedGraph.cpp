#include <bits/stdc++.h>
using namespace std;
//test case
/*
1
6 8
0 1
0 2
2 4
4 5
3 5
1 3
1 4
3 4
o/p :0 1 3 5 4 2
*/

//O(V + E) time | O(V) space
/*
    Each vertex can't be visited twice so there comes the O(V) part
    DFS-visit iterates over the adjacency list of each vertex it visits
    so in the worst case it iterates over all edges. there comes the O(E)
    so out final time complexity is O(V+E)
*/
void dfs(int s, vector<int> g[], bool *vis){
    vis[s] = true;
    cout<<s<<" ";
        for(int i = 0; i < g[s].size(); i++){ // traverse through all the adjacent outgoing edges from a node
            if(vis[g[s][i]] == false){ // dfs only if not visited
                dfs(g[s][i],g,vis);
            }
        }
}

int main(){
 int t;
 cin>>t;
    while(t--){
        int N,E;
        cin>>N>>E;

        vector<int> g[N];
        bool vis[N];

        memset(vis,false, sizeof(vis));

        for(int i = 0; i < E; i++){
            int u,v;//an edge
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0,g,vis);
        cout<<endl;
    }
 return 0;
}

