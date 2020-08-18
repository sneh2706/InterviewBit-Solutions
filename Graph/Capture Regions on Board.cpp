/*

Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

*/

void dfs(vector<vector<char>> &v, int i, int j, int m, int n)
    {
        if(i<0 || j<0 || i>=m || j>=n) return;
        
        if(v[i][j]!='O') return; 
        
        v[i][j] = '1';
        
        dfs(v,i-1,j,m,n);
        dfs(v,i+1,j,m,n);
        dfs(v,i,j-1,m,n);
        dfs(v,i,j+1,m,n);
    }
    
void Solution::solve(vector<vector<char>>& v) 
    {
        int m = v.size();
        if(m==0) return;
        
        int n = v[0].size();
        
        if(m==1 || n==1) return;
        
        for(int i=0; i<m; i+=(m-1))
        {
            for(int j=0; j<n; ++j)
            {
                if(v[i][j]!='X')
                    dfs(v,i,j,m,n);
            }
        }
        
        for(int j=0; j<n; j+=(n-1))
        {
            for(int i=1; i<m-1; ++i)
            {
                if(v[i][j]!='X')
                    dfs(v,i,j,m,n);
            }
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(v[i][j]=='1') v[i][j]='O';
                else v[i][j] = 'X';
            }
        }
    }