/*
    Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
*/

class Solution {
public:
    // we will propagate the max sum from bottom to top
    // in case of negative sum, we will propagate 0 (similar to kadane's algo)
    int path_helper(TreeNode *root, int &max_sum) {
        // base case
        if(!root)
            return 0;
        // recursive calls: postorder traversal
        int left_sum = path_helper(root->left, max_sum);
        int right_sum = path_helper(root->right, max_sum);
        
        // there could be 4 cases:
        // case-1: root node only
        int opt1 = root->val;
        // case-2: left subtree + root node
        int opt2 = left_sum + root->val;
        // case-3: right subtree + root node
        int opt3 = right_sum + root->val;
        // case-4: left subtree + right subtree + root node
        int opt4 = left_sum + right_sum + root->val;
        
        // update the max sum to be the max of these 4 options
        max_sum = max({max_sum, opt1, opt2, opt3, opt4});
        // if we encounter negative sum it's better to not consider the node further
        // root should return max sum with atmost one child only (else would violate the condition of path)
        return max({0, opt1, opt2, opt3});
    }
    
    
    int maxPathSum(TreeNode* root) {
        // edge case
        if(!root)
            return 0;
        
        int max_sum = INT_MIN;
        // call to the helper function
        path_helper(root, max_sum);
        
        return max_sum;
    }
};