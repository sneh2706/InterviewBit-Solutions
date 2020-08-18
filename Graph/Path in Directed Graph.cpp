/*

Given an directed graph having A nodes labelled from 1 to A containing M edges given by matrix B of size M x 2such that there is a edge directed from node

B[i][0] to node B[i][1].

Find whether a path exists from node 1 to node A.

Return 1 if path exists else return 0.

*/

void dfs(int ind, bool *visited, vector<int> graph[]) {
    
    visited[ind] = true;
    for(auto it=graph[ind].begin(); it!=graph[ind].end(); ++it) {
        if(!visited[*it])
        dfs(*it,visited,graph);
    }
    
}
 
int Solution::solve(int A, vector<vector<int> > &B) {
    
    bool visited[A+1] ={false};
    vector<int> graph[A+1];
    
    for(int i=0; i<B.size(); ++i) {
        int a = B[i][0];
        int b = B[i][1];
        graph[a].push_back(b);
    }
    
    dfs(1,visited,graph);
    
    if(visited[A]) return 1;
    return 0;
    
}