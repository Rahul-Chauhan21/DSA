#include <iostream>
#include <vector>

using namespace std;
/*
 test case:
    1
    5 6
    0 1
    4 0
    2 1
    2 3
    3 4
    4 2
    o/p: cycle exists
*/
bool isCyclicUtil(vector<int> adj[], vector<bool>& vis, int curr){
    cout<<"in recursive func for current value :" <<curr << endl;
    if(vis[curr] == true){
        return true;
    }
    vis[curr] = true;
    bool flag = false;
        for(int i = 0; i < adj[curr].size(); i++){
            flag = isCyclicUtil(adj,vis,adj[curr][i]);
            if(flag == true){
                return true;
            }
        }
    vis[curr] = false; // since we are using an array reference
    return false;
}
// O(V + E) time
bool isCyclic(int V, vector<int> adj[]){
    vector<bool> vis(V,false);
    bool flag = false;
        for(int i = 0; i < V; i++){
            vis[i] = true;
                for(int j = 0; j < adj[i].size(); j++){
                    flag = isCyclicUtil(adj,vis,adj[i][j]);
                    // from which u to v we initiated to find a cycle, if it exists
                    cout << i << " j: " << adj[i][j]<<" "<<vis[adj[i][j]] << endl;
                    if(flag == true){
                        return true;
                    }
                }
            vis[i] = false;
        }
    return false;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int V,E;
        cin>>V>>E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        if(isCyclic(V,adj)){
            cout<<"Graph contains a cycle";
        }
        else{
            cout<<"Graph doesn't contain a cycle";
        }
    }
 return 0;
}
