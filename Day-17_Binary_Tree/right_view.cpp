/*
    Problem Link: https://leetcode.com/problems/binary-tree-right-side-view/
*/

void findRightView(TreeNode* root, int level, int &max_level, vector<int> &results) {
    // base case
    if(!root) 
        return;
    // new node (rightmost) of each new level
    if(level > max_level) {
        results.push_back(root->val);
        max_level = level;
    }
    
    // recursive calls: right subtree first
    findRightView(root->right, level + 1, max_level, results);
    findRightView(root->left, level + 1, max_level, results);
}

vector<int> rightSideView(TreeNode* root) {
    int max_level = -1;
    vector<int> results;
    findRightView(root, 0, max_level, results);
    
    return results;
}