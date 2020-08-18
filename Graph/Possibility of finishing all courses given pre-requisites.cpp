/*

There are a total of A courses you have to take, labeled from 1 to A.

Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2].

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Return 1 if it is possible to finish all the courses, or 0 if it is not possible to finish all the courses.

Input Format:

*/

bool cycletill(int x, vector<bool> &visited, vector<bool> &recstack, vector<vector<int>> &v)
{
        visited[x] = true;
        recstack[x] = true;
        
        for(int i=0; i<v[x].size(); ++i)
        {
            if(!visited[v[x][i]] && cycletill(v[x][i],visited,recstack,v))
                return true;
            else if(recstack[v[x][i]])
                return true;
        }
        
        recstack[x] = false;
        return false;
    }
    
    bool cyclic(vector<vector<int>> &v, int n)
    {
        vector<bool> visited(n+1,false);
        vector<bool> recstack(n+1,false);
        
        for(int i=1; i<=n; ++i)
        {
            if(cycletill(i,visited,recstack,v))
                return true;
        }
        
        return false;
    }


int Solution::solve(int n, vector<int> &B, vector<int> &C) 
{
    vector<vector<int>> v(n+1);
        
        for(int i=0; i<B.size(); ++i)
            v[C[i]].push_back(B[i]);
        
        if(cyclic(v,n))
            return false;
        return true;
}
