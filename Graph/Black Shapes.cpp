/*

Given N x M character matrix A of O's and X's, where O = white, X = black.

Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

*/

void dfs(vector<string> &v, vector<vector<bool>> &visited, int i, int j, int m, int n) {
    visited[i][j]=true;
    if(i-1>=0 && v[i-1][j]=='X' && !visited[i-1][j])
    dfs(v,visited,i-1,j,m,n);
    if(i+1<m && v[i+1][j]=='X' && !visited[i+1][j])
    dfs(v,visited,i+1,j,m,n);
    if(j-1>=0 && v[i][j-1]=='X' && !visited[i][j-1])
    dfs(v,visited,i,j-1,m,n);
    if(j+1<n && v[i][j+1]=='X' && !visited[i][j+1])
    dfs(v,visited,i,j+1,m,n);
}
 
int Solution::black(vector<string> &v) {
    int m=v.size();
    int n=v[0].size();
    
    if(m==0 || n==0) return 0;
    
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(v[i][j]=='O')
            visited[i][j]=true;
        }
    }
    
    int count=0;
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(v[i][j]=='X' && !visited[i][j]) {
                dfs(v,visited,i,j,m,n);
                count++;
            }
        }
    }
    return count;
}