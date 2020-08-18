/*

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

*/

TreeNode* newnode(int xn) {
    TreeNode* res = (TreeNode*)malloc(sizeof(TreeNode));
    res->val=x;
    res->left=NULL;
    res->right=NULL;
    return res;
}

TreeNode* arraytobst(vector<int> &v, int s, int e) {
    if(s>e)
    return NULL;
    
    int mid=s+(e-s)/2;
    TreeNode* temp=newnode(v[mid]);
    temp->left=arraytobst(v,s,mid-1);
    temp->right=arraytobst(v,mid+1,e);
    return temp;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    TreeNode* root=NULL;
    ListNode* temp = A;
    vector<int> v;
    while(temp) {
        v.push_back(temp->val);
        temp=temp->next;
    }
    
    return arraytobst(v,0,v.size()-1);
}
