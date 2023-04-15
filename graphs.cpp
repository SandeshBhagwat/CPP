/*  Name : Sandesh Prakash Bhagwat
    Branch : AI&DS
    Div : A
    Roll No : 13
    PRN : 12110367

    ADS Assignment 6A: Graphs
                    BFS, DFS Traverse
*/

#include<bits/stdc++.h>
using namespace std;

pair<int,int> buildGraph(vector<int> adj[]){
    
    int v, e;
    cout << "Enter the number  of vertices:\n";
    cin >> v;
    cout << "Enter the number of edges:\n";
    cin >> e;

    cout << "Enter " << e << " pairs of connected vertices\n";
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return {v,e};
}

void printGraph(vector<int> adj[], int v){
    for(int i=0;  i<v; i++){
        cout << i <<  ":";
        for(auto &j : adj[i]){
            cout << j <<  " ";
        }
        cout << endl;
    }
}
void bfs(vector<int> adj[], int v, int e){
    cout << "\nEnter the starting vertex:\n";
    int start;
    cin >> start;
    vector<bool> vis(e,0);
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while(!q.empty()) {
        int node = q.front(); 
        q.pop(); 
        cout << node << " ";
        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it] = 1; 
                q.push(it); 
            }
        }
    }
    cout << endl;
}

void dfs(vector<int> adj[], int v, int e, vector<bool> &visited, int i){
    visited[i] = 1;
    cout << i <<  " ";
    for(auto &n : adj[i]){
        if(!visited[n])dfs(adj, v, e, visited, n);
    }
}


void ops(vector<int> adj[], int v, int e){
    cout <<"===========================================\n";
    cout << "\nEnter your choice: \n";
    cout << "1. Build Graph\n2. BFS \n3. DFS\n4.Exit\n\n";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:{
            // adj.clear();
            // vector<int> arr[10];
            pair<int,int> p = buildGraph(adj);
            int v = p.first;
            int e = p.second;
            cout << "\nGraph representation using adjecency list\n"; 
            printGraph(adj, v);
            ops(adj, v, e);
            break;
        }

        case 2:{
            bfs(adj, v, e);
            ops(adj, v, e);
            break;
        }
        
        case 3:{
            cout << "Enter the starting vertex:\n";
            int s;
            cin >> s;
            vector<bool> visited(e,0);
            dfs(adj, v, e, visited, s);
            cout << endl;
            ops(adj, v, e);
            break;
        }

        case 4:
            return;
        
        default:{
            cout << "Invalid  choice!!!";
            ops(adj, v, e);
        }

    }
}


int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    vector<int> adj[10];
    ops(adj, 0, 0);

    
    return 0;
}