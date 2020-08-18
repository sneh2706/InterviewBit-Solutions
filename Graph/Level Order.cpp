/*

Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

*/

int height(TreeNode* root) {
    if(!root) return 0;
    return max(height(root->left),height(root->right))+1;
}

vector<vector<int> > Solution::levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    
    int ht=height(root);
    res.resize(ht);
    
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    
    while(!q.empty()) {
        pair p=q.front();  q.pop();
        TreeNode* t=p.first;
        res[p.second].push_back(t->val);
        
        if(t->left)
        q.push({t->left,p.second+1});
        if(t->right)
        q.push({t->right,p.second+1});
    }
    
    return res;
}
