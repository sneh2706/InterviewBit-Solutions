/*

Given a tree with N nodes labelled from 1 to N.

Each node is either good or bad denoted by binary array A of size N where if A[i] is 1 then ithnode is good else if A[i] is 0 then ith node is bad.

Also the given tree is rooted at node 1 and you need to tell the number of root to leaf paths in the tree that contain not more than C good nodes.

NOTE:

Each edge in the tree is bi-directional.

*/

struct node {
    int x;
    set<int> path;
};

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    
    int n = A.size();
    vector<int> graph[n+1];
    
    for(int i=0; i<B.size(); ++i) {
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    
    node st;
    set<int> s;
    s.insert(1);
    st.x = 1;
    st.path = s;
    
    queue<node> q;
    q.push(st);
    
    int count = 0;
    
    while(!q.empty()) {
        
        node top = q.front();
        q.pop();
        
        int flag = 0;
        set<int> s1 = top.path;
        for(auto it=graph[top.x].begin(); it!=graph[top.x].end(); ++it) {
            
            if(s1.find(*it)==s1.end()) {
                
                flag = 1;
                node child;
                set<int> s2 = s1;
                s2.insert(*it);
                child.path = s2;
                child.x = *it;
                q.push(child);
                
            }
            
        }
        
        if(flag == 0) {
            
            int cnt = 0;
            for(auto it=s1.begin(); it!=s1.end(); ++it) {
                if(A[(*it)-1]==1) cnt++;
            }
            
            if(cnt <= C) count++;
            
        }
        
    }
    
    return count;
    
}
