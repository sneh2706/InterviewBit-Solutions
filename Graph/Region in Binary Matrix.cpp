 /*

Given a binary matrix A of size N x M.

Cells which contain 1 are called filled cell and cell that contain 0 are called empty cell.

Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.

If one or more filled cells are also connected, they form a region. Find the length of the largest region.

 */
 
 int cnt;
    
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited)
    {
        ++cnt;
        visited[i][j] = true;
        int m = grid.size();
        int n = grid[0].size();
        
        if(i-1>=0 && grid[i-1][j]==1 && !visited[i-1][j])
            dfs(grid,i-1,j,visited);
        
        if(j-1>=0 && grid[i][j-1]==1 && !visited[i][j-1])
            dfs(grid,i,j-1,visited);
        
        if(i+1<m && grid[i+1][j]==1 && !visited[i+1][j])
            dfs(grid,i+1,j,visited);
        
        if(j+1<n && grid[i][j+1]==1 && !visited[i][j+1])
            dfs(grid,i,j+1,visited);
            
        if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==1 && !visited[i-1][j-1])
        dfs(grid,i-1,j-1,visited);
        
        if(i-1>=0 && j+1<n && grid[i-1][j+1]==1 && !visited[i-1][j+1])
        dfs(grid,i-1,j+1,visited);
        
        if(i+1<m && j-1>=0 && grid[i+1][j-1]==1 && !visited[i+1][j-1])
        dfs(grid,i+1,j-1,visited);
        
        if(i+1<m && j+1<n && grid[i+1][j+1]==1 && !visited[i+1][j+1])
        dfs(grid,i+1,j+1,visited);
    }
 
int Solution::solve(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int res = 0;
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j]==1)
                {
                    cnt = 0;
                 
                    if(!visited[i][j])
                    {
                        cnt = 0;
                        dfs(grid,i,j,visited);
                        res = max(res,cnt);
                    }
                       
                }
            }
        }
        
        return res;
}