#include <bits/stdc++.h>
using namespace std;
//test case
/*
6
8
0 1
0 2
1 3
3 5
3 4
4 2
4 1
4 5
o/p:0 1 2 3 5 4

6
8
0 2
0 1
1 3
3 4
3 5
4 1
4 2
4 5

o/p: 0 2 1 3 4 5

6
8
0 2
0 1
1 3
3 4
3 5
4 2
4 1
4 5

o/p: 0 2 1 3 4 5
*/

// O(V + E) time | O(V) space
void bfs(int s, vector<int> adj[], bool* vis){
    queue<int> q;
    q.push(s);
    vis[s] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cout<< curr << " ";
                for(int i = 0; i < adj[curr].size(); ++i){
                    if(vis[adj[curr][i]] == false){
                        q.push(adj[curr][i]);
                        vis[adj[curr][i]] = true;
                    }
                }
        }
}

int main(void){
 int t;
 cin>>t;
    while(t--){
        int N,E;
        cin>>N>>E;

        vector<int> adj[N];
        bool vis[N];
        memset(vis, false, sizeof(vis));

        for(int i = 0; i < E; i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        bfs(0,adj,vis);
        cout<<endl;
    }
 return 0;
}
