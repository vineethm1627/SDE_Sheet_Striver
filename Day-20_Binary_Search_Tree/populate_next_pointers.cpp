/*
    Problem Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/

Node *connect(Node *root) {
    // edge case
    if(!root)
        return NULL;

    queue<Node*> q;
    q.push(root);
    Node *curr;
    // perform BFS: level order traversal
    while(!q.empty()) {
        int n = q.size(); // denotes the number of nodes in the current level
        for(int i = 0; i < n; i++) {
            curr = q.front();
            q.pop();
            // make the last node point to NULL: no node on its right
            if(i == n - 1)
                curr->next = NULL;
            // make the current node point to the next node in the queue
            else    
                curr->next = q.front();
            // add the children in the queue if they exist
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    return root;
}
