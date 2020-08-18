/*

Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

*/

bool dfs(int ind, vector<bool> &visited, vector<bool> &recstack, vector<int> v[]) {
    
    visited[ind] = true;
    recstack[ind] = true; 
    for(auto it=v[ind].begin(); it!=v[ind].end(); ++it) {
        if(!visited[*it] && dfs(*it,visited,recstack,v))
        return true;
        else if(recstack[*it])
        return true;
    }
    
    recstack[ind] = false;
    return false;
    
}

int Solution::solve(int n, vector<vector<int> > &m) {
    vector<int> v[n+1];
    
    for(int i=0; i<m.size(); ++i) 
    v[m[i][0]].push_back(m[i][1]);
    
    vector<bool> visited(n+1,false);
    vector<bool> recstack(n+1,false);
    
    for(int i=1; i<=n; ++i) {
        if(dfs(i,visited,recstack,v))
        return 1;
    }
    
    return 0;
}
