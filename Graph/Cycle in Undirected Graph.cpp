/*

Given an undirected graph having A nodes labelled from 1 to A with M edges given in a form of matrix B of size M x 2 where (B[i][0], B[i][1]) represents two nodes B[i][0] and B[i][1] connected by an edge.

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

*/

bool isCyclicUtil(int v, bool visited[], int parent, vector<int> adj[]) 
{ 
    visited[v] = true; 
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) 
    { 
        if (!visited[*i]) 
        { 
           if (isCyclicUtil(*i, visited, v,adj)) 
              return true; 
        } 
        else if (*i != parent) 
           return true; 
    } 
    return false; 
} 
bool isCyclic(vector<int> adj[], int n) 
{ 
    bool *visited = new bool[n]; 
    for (int i = 1; i < n; i++) 
        visited[i] = false; 
    for (int u = 1; u < n; u++) 
        if (!visited[u]) 
          if (isCyclicUtil(u, visited, -1,adj)) 
             return true; 
  
    return false; 
}
 
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> v[A+1];
    for(int i=0; i<B.size(); ++i) {
        int x= B[i][0];
        int y=B[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    return isCyclic(v,A+1);
}