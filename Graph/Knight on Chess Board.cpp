/*

Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

Knight's movements on a chess board

If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.

*/

struct node {
    int xco;
    int yco;
    int cost;
};
 
bool legal(int x, int y, int m, int n) {
    if(x>=0 && x<m && y>=0 && y<n) return true;
    return false;
}
 
int Solution::knight(int m, int n, int x, int y, int d1, int d2) {
    int dx[]={-1,-1,-2,-2,1,1,2,2};
    int dy[]={-2,2,-1,1,-2,2,-1,1};
    x--;y--;d1--;d2--;
    
    
    vector<vector<int>> visited(m,vector<int>(n,-1));
    
    node n1;
    n1.xco=x;
    n1.yco=y;
    n1.cost=0;
    
    queue<node> q;
    q.push(n1);
    visited[x][y]=0;
    
    while(!q.empty()) {
        node n2 = q.front();    q.pop();
        int x_co=n2.xco;
        int y_co=n2.yco;
        int cost_xy=n2.cost;
        if(x_co==d1 && y_co==d2) return cost_xy;
        
        for(int i=0; i<8; ++i) {
            int x1=x_co+dx[i];
            int y1=y_co+dy[i];
            if(legal(x1,y1,m,n) && ((visited[x1][y1]==-1)||(visited[x1][y1]>cost_xy+1))) {
                node tmp;
                tmp.xco=x1;
                tmp.yco=y1;
                tmp.cost=cost_xy+1;
                q.push(tmp);
                visited[x1][y1]=cost_xy+1;
            }
        }
    }
    return -1;
}