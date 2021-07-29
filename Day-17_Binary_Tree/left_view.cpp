/*
    Problem Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
*/

// helper function to find the nodes visible from the left view
void left_helper(Node *root, int level, int &max_level, vector<int> &results) {
    // base case
    if(!root)
        return;
    
    // store the first encountered node (leftmost) at each new level
    if(level > max_level) {
        max_level = level;
        results.push_back(root->data);
    }
    // recursive calls: left subtree first
    left_helper(root->left, level + 1, max_level, results);
    left_helper(root->right, level + 1, max_level, results);
}

vector<int> leftView(Node *root) {
    vector<int> results;
    int max_level = -1;
    // call to the helper function
    left_helper(root, 0, max_level, results);

    return results;
}