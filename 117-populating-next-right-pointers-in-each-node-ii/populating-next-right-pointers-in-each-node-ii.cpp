class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            Node* prev = NULL;

            for (int i = 0; i < sz; i++) {
                Node* node = q.front();
                q.pop();

                if (prev != NULL)
                    prev->next = node;

                prev = node;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }
};
