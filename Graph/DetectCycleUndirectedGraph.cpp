#include <iostream>
#include <vector>
using namespace std;
// O(V + E) time
/*
    test case:
    1
    4 4
    0 1
    0 2
    0 3
    2 3
    o/p: 1

    1
    4 3
    0 1
    0 3
    1 2
    o/p: 0
*/
bool isCyclicUtil(vector<int>adj[], vector<int> vis, int curr){
    if(vis[curr] == 2){
        return true;
    }
    vis[curr] = 1;
        for(int i = 0; i < adj[curr].size(); i++){
            if(vis[adj[curr][i]] == 1){
                vis[adj[curr][i]] = 2;
            }
            else{
                if(isCyclicUtil(adj,vis,adj[curr][i])){
                    return true;
                }
            }
        }
    return false;
}

bool isCyclic(int V, vector<int> adj[]){
    vector<int> vis(V,0);
        for(int i = 0; i < V; i++){
            vis[i] = 1;
                for(int j = 0; j < adj[i].size(); j++){
                    //cout<<i <<" j :" <<adj[i][j]<<" "<<vis[adj[i][j]]<<endl;
                    if(isCyclicUtil(adj,vis,adj[i][j])){
                        return true;
                    }
                    //cout<<i <<" j :" <<adj[i][j]<<" "<<vis[adj[i][j]]<<endl;
                }
            vis[i] = 0;
        }
    return false;
}

int main(void){
    int T;
    cin >> T;

    while(T--){
        int V,E;
        cin>>V>>E;
        vector<int> adj[V];

            for(int i = 0; i < E; i++){
                int u,v;
                cin>>u>>v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

        cout<<isCyclic(V,adj);
    }
 return 0;
}
