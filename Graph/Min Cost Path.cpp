/*

You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

Your target is to go from top left corner to the bottom right corner of the matrix.

But there are some restrictions while moving along the matrix:

If you follow what is written in the cell then you can move freely.
But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.

*/

struct node {
    int x;
    int y;
    int cost;
};
 
struct comp {
    bool operator()(const node &n1, const node &n2) {
        return n1.cost > n2.cost;
    }
};
 
int Solution::solve(int m, int n, vector<string> &C) {
    
    m = C.size(); if(m==0) return 0;
    n = C[0].size(); if(n==0) return 0;
    
    vector<vector<int>> cost(m,vector<int>(n,0));
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    
    priority_queue<node,vector<node>,comp> pq;
    
    node st_node;   st_node.x=0;    st_node.y=0;    st_node.cost=0;
    cost[0][0]=0;    visited[0][0]=true;
    pq.push(st_node);
    
    while(!pq.empty()) {
        
        node topnode = pq.top(); pq.pop();
        if(topnode.x==m-1 && topnode.y==n-1) return topnode.cost;
        
        int x1=topnode.x,   y1=topnode.y,   costhere=topnode.cost;
        
        int upcost = costhere + (C[x1][y1]!='U' ? 1 : 0);
        int dncost = costhere + (C[x1][y1]!='D' ? 1 : 0);
        int ltcost = costhere + (C[x1][y1]!='L' ? 1 : 0);
        int rtcost = costhere + (C[x1][y1]!='R' ? 1 : 0);
        
        if(x1-1>=0) {
            if(!visited[x1-1][y1] || cost[x1-1][y1]>upcost) {
                visited[x1-1][y1]=true;
                cost[x1-1][y1]=upcost;
                node tmpnode; 
                tmpnode.x=x1-1;     tmpnode.y=y1;   tmpnode.cost=upcost;
                pq.push(tmpnode);
            }
        }
        
        if(y1-1>=0) {
            if(!visited[x1][y1-1] || cost[x1][y1-1]>ltcost) {
                visited[x1][y1-1]=true;
                cost[x1][y1-1]=ltcost;
                node tmpnode; 
                tmpnode.x=x1;     tmpnode.y=y1-1;   tmpnode.cost=ltcost;
                pq.push(tmpnode);
            }
        }
        
        if(x1+1<m) {
            if(!visited[x1+1][y1] || cost[x1+1][y1]>dncost) {
                visited[x1+1][y1]=true;
                cost[x1+1][y1]=dncost;
                node tmpnode; 
                tmpnode.x=x1+1;     tmpnode.y=y1;   tmpnode.cost=dncost;
                pq.push(tmpnode);
            }
        }
        
        if(y1+1<n) {
            if(!visited[x1][y1+1] || cost[x1][y1+1]>rtcost) {
                visited[x1][y1+1]=true;
                cost[x1][y1+1]=rtcost;
                node tmpnode; 
                tmpnode.x=x1;     tmpnode.y=y1+1;   tmpnode.cost=rtcost;
                pq.push(tmpnode);
            }
        }
        
    }
    
    return 0;
}