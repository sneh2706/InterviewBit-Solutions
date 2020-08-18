/*

There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

*/

struct subset{
    int parent;
    int rank;
};

int find(vector<subset> &v, int i) {
    if(v[i].parent != i)
    v[i].parent = find(v,v[i].parent);
    
    return v[i].parent;
}

void unionof(vector<subset> &v, int x, int y) {
    int xroot = find(v,x);
    int yroot = find(v,y);
    
    if(v[xroot].rank < v[yroot].rank)
    v[xroot].parent = yroot;
    else if(v[xroot].rank > v[yroot].rank)
    v[yroot].parent = xroot;
    else {
        v[yroot].parent = xroot;
        v[xroot].rank++;
    }
}

int comp(vector<int> v1, vector<int> v2) {
    if(v1[2]<v2[2])
    return 1;
    
    return 0;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(),B.end(),comp);
    
    vector<subset> v(A+1);
    for(int i=1; i<=A; ++i) {
        v[i].parent = i;
        v[i].rank = 0;
    }
    
    int e=0, i=0;
    int res=0;
    while(e<A-1 && i<B.size()) {
        int x1 = B[i][0];
        int y1 = B[i][1];
        int cost = B[i][2];
        i++;
        
        int x = find(v,x1);
        int y = find(v,y1);
        
        if(x!=y) {
            res += cost;
            e++;
            unionof(v,x,y);
        }
    }
    
    return res;
}
