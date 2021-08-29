/*
    Largest BST: https://practice.geeksforgeeks.org/problems/largest-bst/1
*/

struct bst {
    bool isBST;
    int size;
    int min, max;
};

class Solution{
    public:
        int size;
    // helper function
    bst find(Node *root) {
        // base case: null node
        if(!root) 
            return {true, 0, INT_MAX, INT_MIN};

        // leaf node
        if(!root->left && !root->right) 
            return {true, 1, root->data, root->data};
           
        // recursive calls: postorder traversal: LRN
        bst left = find(root->left);
        bst right = find(root->right);
        
        // condition check
        if(left.isBST && right.isBST) {
            if(root->data > left.max && root->data < right.min) {
                int min_val = left.min;
                int max_val = right.max;
                // condition check
                if(min_val == INT_MAX)
                    min_val = root->data;
                if(max_val == INT_MIN)
                    max_val = root->data;
                
                return {1, left.size + right.size + 1, min_val, max_val};
            }
        }
        return {0, max(left.size, right.size), 0, 0};
    }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
        bst b = find(root);
        return b.size;
    }
};