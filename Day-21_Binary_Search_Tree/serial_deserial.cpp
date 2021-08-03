/*
    Problem Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
*/

// encode a tree into a single string
// preorder tree traversal
string serialize(TreeNode *root) {
    // base case
    if(!root)
        return "NULL,";
    // recursive calls
    return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
}

// helper function to create a queue (level order traversal)
TreeNode *deserialize_helper(queue<string> &q) {
    string front = q.front();
    q.pop();
    // base case
    if(front == "NULL")
        return NULL;
    // create the current new node
    TreeNode *root = new TreeNode(stoi(front));
    // recursive calls
    root->left = deserialize_helper(q);
    root->right = deserialize_helper(q);

    return root;
}

// decodes encoded data to tree
TreeNode *deserialize(string data) {
    queue<string> q;
    string s;
    for(char &c : data) {
        if(c == ',') {
            q.push(s);
            // reset the string
            s = "";
        }
        else    
            s += c;
    }
    if(!s.empty())
        q.push(s);
    // call to the helper function to deserialize
    return deserialize_helper(q);
}