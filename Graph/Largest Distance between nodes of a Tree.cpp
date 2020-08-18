/*

Given an arbitrary unweighted rooted tree which consists of N nodes.

The goal of the problem is to find largest distance between two nodes in a tree.

Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).

The nodes will be numbered 0 through N - 1.

The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.



*/

typedef long long ll;
int maxd, maxnode;

void dfs(int ind, int d, vector<int> v[], vector<bool> visited, int n) {
  visited[ind]=true;
  if(d>maxd) {
    maxd=d;
    maxnode=ind;
  }

  for(auto it=v[ind].begin(); it!=v[ind].end(); ++it) {
    if(!visited[*it])
    dfs(*it,d+1,v,visited,n);
  }
}

int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<int> v[n];
    
    int root;
    
    for(int i=0; i<n; ++i) {
        if(A[i]==-1)
        root=i;
        else {
            v[A[i]].push_back(i);
            v[i].push_back(A[i]);
        }
    }
    
    int res=0;
    vector<bool> visited(n,false);

    maxd=-1;
    dfs(root,0,v,visited,n);

    for(ll i=0; i<n; ++i) visited[i]=false;
    maxd=-1;
    dfs(maxnode,0,v,visited,n);

    return maxd;
}
